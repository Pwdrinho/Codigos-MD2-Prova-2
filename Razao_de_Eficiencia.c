/*=========================================================
Questao 3 - A Razão de Eficiência de um Número.

Autor: Pedro Lucas B. da Silva - 241025710 
Data: 17/10/2025
=========================================================*/
#include <stdio.h>
#include <stdbool.h>
//=================================================================
//Verificar se número é primo, vai servir de manobra pra otimizar a função tau
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
//Função tau τ(N) = número total de divisores de 𝑁
int tau(int n){
    if(primo(n)) return 2; //otimização com função primo

    int contador = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0) contador++;
    }
    return contador;
}
//=================================================================
//Função sigma σ(N) = soma de todos os divisores de N
int sigma(int n){
    int soma = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) soma += i;
    }
    return soma;
}
//=================================================================
//Trial Division