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

        printf("%d = %d * %d + %d", a, b, quociente, resto);
        b = a;
        a = resto;
    }
    printf("d= %d \n", a);
    return a;
}

//=================================================================


int main(){
    //Cabeçalho
    printf("+=========================================+ \n");
    printf("|Pedro Lucas Barbosa da Silva - 241025710 | \n"); 
    printf("+=========================================+ \n");

    //Etapa 1 Fatoração Interativa (Método ρ de Pollard)
    //Entrada de dados - inicialização das variáveis

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

    // Implementação do método ρ de Pollard:
    // Utilizando a função g(x) = (x²+1) mod N
    // Semente (Xo) = 2



    return 0;
}