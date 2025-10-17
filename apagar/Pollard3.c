#include <stdio.h>

//Método para primeiro verificar se o número é primo
//Retorna 1 se n for primo, 0 caso contrário
int primo(int n){
    int i;
    if(n < 2) return 0; //Não existe primo menor que 2

    for (i = 2; i < n; i++)
        if (n % i == 0) {
            return 0;// achou divisor → não é primo
    }
    return 1; // nenhum divisor encontrado → é primo
}
//Método para encontrar os fatores primos p e q
//Não funcional para nosso caso
void FatoresPrimos(int N) {
    for(int i = 2; i <= N / 2; i++){
        if(N % i == 0 && primo(i)){
            int q = N / i;
            if(primo(q)){
                printf("Fatores primos de %d: %d e %d \n", N, i, q);
                return; // Achamos os dois primos
            }
        }
    }
    printf("Nao foi possivel encontrar dois fatores primos para %d. \n", N);
}

int main(){
    //Etapa 1 Fatoração Interativa (Método ρ de Pollard)
    //Entrada de dados - inicialização das variáveis

    //Verificação se condição de co-primos (primos entre si)
    //N1 vai se chamar p
    //N2 vai se chamar q

    /*
    int p, q;
    printf("Digite os dois numeros primos (p e q): \n");
    scanf("%d %d", &p, &q);

    // Verifica se estão no intervalo permitido
    if ((p < 100 || p > 9999) || (q < 100 || q > 9999)) {
    printf("Erro: Cada numero deve ter entre 3 e 4 digitos (100 a 9999).\n");
    return 1;
    }
    if(p == q){
        printf("Para melhor execucao do Metodo ρ de Pollard, use primos distintos \n");
        printf("Deseja continuar? \n");
    }
    


    if(primo(p) == 0 || primo(q) == 0){
        printf("p e/ou q nao sao primos. \n");
        return 1;
    }
    printf("p e/ou q sao primos");
    */

    //int n = p * q;
    //int z = (p - 1) * (q - 1);

    return 0;
}