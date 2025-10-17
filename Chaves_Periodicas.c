/*=========================================================
Chaves Periódicas

Autor: Pedro Lucas B. da Silva - 241025710 
Data: 15/10/2025
=========================================================*/
#include <stdio.h>

//=================================================================
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
//=================================================================
int MMC(int a, int b) {
    int mmc = 0;
    int m = MDC(a, b);
    mmc = (a / m) * b;
    printf("O MMC(%d, %d) = %d \n", a, b, mmc);
    return mmc;
}
//=================================================================
int main(){
    printf("+=========================================+ \n");
    printf("|Pedro Lucas Barbosa da Silva - 241025710 | \n"); 
    printf("+=========================================+ \n");

    printf("\n");
    printf("Problemas das Chaves Periodicas \n");
    printf("Etapa 1 - Entrada de Dados \n");
    printf("\n");
    
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);
    if (N < 1 || N > 10){
        printf("Valor invalido para N. Deve estar entre o intervalo 1 e 10. \n");
        return 0;
    }; //Verificação das restrições do N

    int C[10]; //C de ciclos.
    printf("Digite os valores dos ciclos (2 a 20): ");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &C[i]);
        if (C[i] < 2 || C[i] > 20) {
            printf("C[%d] fora do intervalo (2..20) \n", i);
            return 0;
        }
    } //Verificação das restrições do C

    printf("Etapa 2 - Calculo do ano sincronizado \n");
    printf("Ano 0: todas as chaves ativadas simultaneamente.\n");
    printf("Calculando o primeiro ano futuro (X > 0) em que todas as chaves se sincronizam...\n");
    printf("\n");

    int ano_sincronizado = C[0];
    for (int i = 1; i < N; ++i) {
        int g = MMC(ano_sincronizado, C[i]);
        ano_sincronizado = g;
        if (ano_sincronizado > 50){
            printf("Não é possivel afimar dentro do limite de 50 anos \n");
            break;
        }
    }
    if (ano_sincronizado <= 50) {
        printf("O Ano (X > 0) mais proximos onde todas as chaves serao ativadas simultaneamente: \n");
        printf("%d \n", ano_sincronizado);
    }
    printf("\n");

    printf("Encerrando o programa! Da questao 2 - Chaves Periodicas. \n");
    return 0;
}