/*

Sistema RSA com Fatoração ρ de Pollard e Aplicação de Teoremas Modulares em Três Etapas.

Autor: Pedro Lucas B. da Silva - 241025710 
Data: 15/10/2025
=========================================================
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//=================================================================
//Método para verificar se o número é primo
//Retorna true se n for primo, false caso contrário
bool primo(int n){
    int i;
    if(n < 2) return false; //Não existe primo menor que 2

    for (i = 2; i < n; i++)
        if (n % i == 0) {
            return false;// achou divisor → não é primo
    }
    return true; // nenhum divisor encontrado → é primo
}
//=================================================================
//Método para verificar se o número é composto
//retorna true se for composto, false caso contrário **apagar
bool Composto(int n) {
    return (n > 1 && !primo(n));
}
//=================================================================
//Método MDC retorna o mdc por meio do teorema de Euclides
int MDC(int a, int b) {
    printf("MDC(%d, %d) \n", a, b);
    while (b != 0) {
        int quociente = a / b;
        int resto = a % b;

        printf("%d = %d * %d + %d \n", a, b, quociente, resto);
        a = b;
        b = resto;
    }
    printf("d= %d \n", a);
    return a;
}
//=================================================================
//Método Pollard Rho utilizando a função g(x)=x²+1 e semente x0 = 2
int pollard_rho(int n){

    printf("== Fatorando o numero: %d ==\n", n);
    //Caso Base onde o menor primo divisor seria o 2
    if(n % 2 == 0){
        printf("O número é par. Um fator é 2.\n");
        printf("Os fatores de %d são 2 e %d.\n", n, n / 2);
        return 2;
    }
    const int semente = 2; //x0 = 2
    int x = semente;
    int y = semente;
    int d = 1;  

    while (d == 1){
        x = ((x * x + 1) % n);
        
        y = ((y * y + 1) % n);
        y = ((y * y + 1) % n);

        printf("|%d, %d| mod %d \n", x, y, n);
        d = MDC(n, abs(x - y));
        printf("Resultado: %d \n", d);

        if (d == n){
            return -1; //Erro que não deveria acontecer
        }
    }
    return d;
}

// Faltando mostrar as iterações e contar qual iteração é

//=================================================================
int main(){
    //Cabeçalho
    printf("+=========================================+ \n");
    printf("|Pedro Lucas Barbosa da Silva - 241025710 | \n"); 
    printf("+=========================================+ \n");

    printf("\n");
    printf("Etapa 1 Fatoracao Interativa (Metodo ρ de Pollard) \n");
    printf("Entrada de dados - inicializacao das variaveis \n");
    printf("\n");

    int N1, N2;
do {
    printf("*Aviso: o Metodo ρ de Pollard eh mais eficiente quando cada Ni eh produto primos distintos (semiprimos).* \n");
    printf("Insira dois numeros compostos 'a' e 'b' entre 100 e 9999:");
    scanf("%d %d", &N1, &N2);

    // Verifica se estão no intervalo permitido
    if ((N1 < 100 || N1 > 9999) || (N2 < 100 || N2 > 9999)) {
        printf("Erro: Cada numero deve ter entre 3 e 4 digitos (100 a 9999).\n");
    }
    // Verifica se os dois são Distintos
    if(N1 == N2){
        printf("Para melhor execucao do Metodo ρ de Pollard, use numeros compostos distintos \n");
    }
    // Verifica se os dois são compostos
    if (!Composto(N1) || !Composto(N2)) {
        printf("Erro: Ambos os numeros devem ser compostos (nao primos).\n\n");
    }
} while ((N1 < 100 || N1 > 9999) || (N2 < 100 || N2 > 9999) || (N1 == N2) || (!Composto(N1) || !Composto(N2)));

    printf("\n");
    printf("Verificao bem sucedida!. Os numeros %d e %d atendem aos criterios", N1, N2);
    printf("\n");

    printf("Etapa 1.5 Aplicando o metodo Pollard Rho nos nossos %d e %d \n", N1, N2);
    printf("\n");

    int p = pollard_rho(N1);
    int cofatorN1; // 1. Declara a variável do segundo cofator de N1
    if (p != 0) cofatorN1 = N1 / p; // 2. Se p não for zero, calcula a divisão 
        else cofatorN1 = 0;      // 3. Senão, atribui 0 para segurança
    if (p <= 1 || p == cofatorN1 || cofatorN1 <= 1 || !primo(cofatorN1) || !primo(p)){
        printf("Erro: O N2: %d não atende aos requisitos, possuir produto de primos distintos. Os fatores obtidos foram: %d e %d \n", N1, p, cofatorN1);
        return 1;
    }

    int q = pollard_rho(N2);
    int cofatorN2; // 1. Declara a variável do segundo cofator de N1
    if (q != 0) cofatorN2 = N2 / q; // 2. Se p não for zero, calcula a divisão 
        else cofatorN2 = 0;      // 3. Senão, atribui 0 para segurança
    if (q <= 1 || q == cofatorN2 || cofatorN2 <= 1 || !primo(cofatorN2) || !primo(q)){
        printf("Erro: O N2: %d não atende aos requisitos, possuir produto de primos distintos. Os fatores obtidos foram: %d e %d \n", N2, q, cofatorN2);
        return 1;
    }
    printf("\n");
    printf("Fatores Primos p e q encontrados \n");
    printf("p = %d \n", p);
    printf("q = %d \n", q);
    printf("\n");
    return 0;
}