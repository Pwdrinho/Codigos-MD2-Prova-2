/*=========================================================
Questao 3 - A Razão de Eficiência de um Número.
Autor: Pedro Lucas B. da Silva - 241025710 
Data: 17/10/2025
=========================================================*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//=================================================================

 long long potencia(int base, int expoente){
     long long resultado = 1;
    for(int i = 0; i < expoente; ++i){
        resultado *= base;
    }
    return resultado;
}
//=================================================================
int main(){
    printf("+=========================================+ \n");
    printf("|Pedro Lucas Barbosa da Silva - 241025710 | \n");
    printf("+=========================================+ \n");
    printf("\n");
    
    printf("Razao de Eficiencia de um numero \n");
    printf("Etapa 1 - Entrada de dados \n");
    printf("\n");
    int N;
    printf("Digite um numero inteiro N positivo e menor que 105: \n");
    scanf("%d", &N);
    if(N < 1 || N > 105){
        printf("Numero N inserido fora do intervalo inserido \n");
        return 1;
    }
    printf("\n");
    printf("Etapa 2 - Fatoracao Prima \n");
    printf("Decompor %d em seus fatores primos utilizando o metodo Trial Division \n", N);
    printf("\n");
    
    int n = N;

    int primos[32];
    int expoentes[32];
    int contador_fatores_primos = 0;

    if (n == 1) {
        printf(" Quando n = 1, encontramos um caso especial \n");
        printf("\n");
        printf("tau(1) = 1\n");
        printf("sigma(1) = 1\n");
        printf("\n");
        printf("A Razao de Eficiencia = (sigma(1) / tau(1)) eh:\n\n");
        printf("Razao de Eficiencia = %-12.2f \n", 1.00);
        return 0;
    }

    // Fator 2
    int count = 0;
    while (n % 2 == 0) {
        printf("  -> n = %d. Divisivel por 2. Novo n = %d / 2 = %d\n", n, n, n / 2);
        count++;
        n /= 2;
    }
    if (count > 0) {
        primos[contador_fatores_primos] = 2;
        expoentes[contador_fatores_primos] = count;
        contador_fatores_primos++;
        printf("Fator primo: 2, Expoente: %d\n", count);
    }

    // Fatores impares
    for (int i = 3; (long long)i * i <= n; i += 2) { // Otimização: testar até a raiz quadrada de n
        printf("Testando divisor impar i = %d. Condicao do loop: %d * %d <= %d (%s)\n", i, i, i, n, ((long long)i * i <= n) ? "true" : "false");
        count = 0;
        while (n % i == 0) {
            printf("    -> n = %d. Divisivel por %d. Novo n = %d / %d = %d\n", n, i, n, i, n / i);
            count++;
            n /= i;
        }
        if (count > 0) {
            primos[contador_fatores_primos] = i;
            expoentes[contador_fatores_primos] = count;
            contador_fatores_primos++;
            printf("Fator primo: %d, Expoente: %d\n", i, count);
        }
    }

    // Se n ainda for maior que 1, ele é um fator primo
    if (n > 1) {
        primos[contador_fatores_primos] = n;
        expoentes[contador_fatores_primos] = 1;
        contador_fatores_primos++;
        printf("Fator primo: %d, Expoente: 1\n", n);
    }

    printf("\nEtapa 3 - Calculo de tau(N) e sigma(N)\n\n");

    // Cálculo de tau(N)
    long long tau = 1;
    printf("Calculando tau(%d) (numero de divisores):\n", N);
    printf("  Formula: tau(N) = (a1 + 1) * (a2 + 1) * ...\n");
    printf("  tau = 1 (valor inicial)\n");
    for (int i = 0; i < contador_fatores_primos; i++) {
        printf("  Para o fator %d com expoente %d:\n", primos[i], expoentes[i]);
        printf("    -> tau = tau * (%d + 1) = %llu * %d = %llu\n", expoentes[i], tau, expoentes[i] + 1, tau * (long long)(expoentes[i] + 1));
        tau *= (expoentes[i] + 1);
    }
    printf("Resultado final: tau(%d) = %llu\n", N, tau);

    // Cálculo de sigma(N)
    long long sigma = 1;
    printf("\nCalculando sigma(%d) (soma dos divisores):\n", N);
    printf("  Formula: sigma(N) = PRODUTO [ (p^(a+1) - 1) / (p - 1) ]\n");
    printf("  sigma = 1 (valor inicial)\n");
    for (int i = 0; i < contador_fatores_primos; i++) {
        long long p = primos[i];
        int a = expoentes[i];
        long long p_pow = potencia(p, a + 1);
        long long termo = (p_pow - 1) / (p - 1);
        printf("  Para o fator p=%llu com expoente a=%d:\n", p, a);
        printf("    Termo = ((%llu^%d - 1) / (%llu - 1)) = ((%llu - 1) / %llu) = %llu\n", p, a + 1, p, p_pow, p - 1, termo);
        printf("    -> sigma = sigma * termo = %llu * %llu = %llu\n", sigma, termo, sigma * termo);
        sigma *= termo;
    }
    printf("Resultado final: sigma(%d) = %llu\n", N, sigma);

    printf("\nEtapa 4 - Calculo da Razao de Eficiencia\n");
    double razao = (double)sigma / tau;
    printf("Razao = sigma(%d) / tau(%d) = %llu / %llu\n", N, N, sigma, tau);
    printf("\n");
    printf("Resultado Final:\n");
    printf("A Razao de Eficiencia de %d eh: %.2f\n", N, razao);

    printf("Encerrando o programa! Da questao 3 - A Razão de Eficiência de um Número. \n");

    return 0;
}