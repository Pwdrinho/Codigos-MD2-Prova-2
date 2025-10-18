/*=========================================================
Questão 2 - Chaves Periódicas.

Autor: Pedro Lucas B. da Silva - 241025710 
Data: 17/10/2025
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

        printf("\n");
        printf("Etapa 3 - Verificacao do possivel resultado \n");
        printf("\n");

        int verificado = 1;
        for (int i = 0; i < N; ++i) {
            printf("%d mod %d = %d \n", ano_sincronizado, C[i], (ano_sincronizado % C[i]));
            if (ano_sincronizado % C[i] != 0) {
                verificado = 0;
                break;
            }
        }
        if (verificado) {
            printf("\n");
            printf("Verificacao bem sucedida: %d mod C[i] = 0 para todos os C[i].\n", ano_sincronizado);
        } else {
            printf("\n");
            printf("Verificacao falhou: %d nao eh multiplo de todos os C[i].\n", ano_sincronizado);
            printf("Nao e possivel sincronizar as chaves no intervalo de 1 a 50 anos.\n");
            return 0;
        }

        printf("\n");
        printf("O Ano (X > 0) mais proximos onde todas as chaves serao ativadas simultaneamente: ");
        printf("%d \n", ano_sincronizado);
    }
    printf("\n");

    printf("Encerrando o programa! Da questao 2 - Chaves Periodicas. \n");
    return 0;
}