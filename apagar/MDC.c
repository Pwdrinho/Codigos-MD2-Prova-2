#include <stdio.h>

int MDC(int a, int b) {
    printf("MDC(%d, %d) \n", a, b);
    while (b != 0) {
        int quociente = a / b;
        int resto = a % b;

        printf("%d = %d * %d + %d \n", a, b, quociente, resto);
        a = b;
        b = resto;
    }
    printf("MDC = %d \n", a);
    return a;
}

int main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    int resultado = MDC(num1, num2);
    printf("O MDC de %d e %d eh: %d\n", num1, num2, resultado);
    return 0;

}

int MMC(int a, int b) {
    int mmc = 0;
    mmc = a / MDC(a, b) * b;
    printf("O MMC(%d, %d) = %d", a, b, mmc);
    return mmc;
}
//=================================================================