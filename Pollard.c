/*=========================================================
Sistema RSA com Fatoração ρ de Pollard e Aplicação de Teoremas Modulares em Três Etapas.

Autor: Pedro Lucas B. da Silva - 241025710 
Data: 15/10/2025
=========================================================*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
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

    int quociente = a / b;
    int resto = a % b;

    printf("%d = %d * %d + %d \n", a, b, quociente, resto);
    
    if (resto == 0) {
        printf("resto = 0\n");
        return b;
    }
    while (b != 0) {
        int quociente = a / b;
        int resto = a % b;

        printf("%d = %d * %d + %d \n", a, b, quociente, resto);

        a = b;
        b = resto;
    }
     printf("resto = %d \n", a);
    return a;
}
//=================================================================
//Método Pollard Rho utilizando a função g(x)=x^2+1 e semente x0 = 2 e C = 1
int pollard_rho(int n){

    printf("\n");
    printf("== Fatorando o numero: %d ==\n", n);
    printf("Considerando x0 = 2 e c = 1 \n");
    printf("\n");
    //Caso Base onde o menor primo divisor seria o 2
    if(n % 2 == 0){
        printf("O numeroehpar. Um fatoreh2.\n");
        printf("Os fatores de %d são 2 e %d.\n", n, n / 2);
        return 2;
    }
    const int semente = 2; //x0 = 2
    int x = semente;
    int y = semente;
    int d = 1;  
    int iteracao = 0; // Contador de iterações
    int resultadoX;
    int resultadoY;

    while (d == 1){
        iteracao++;
        printf("Iteracao %d: \n", iteracao);
        printf("g(x) = %d^2 + 1 = %d mod %d \n", x, (x * x + 1), n);
        resultadoX = x = ((x * x + 1) % n);
        printf("Resultado: %d \n", resultadoX);
        printf("\n");
        
        printf("g(y) = %d^2 + 1 = %d mod %d \n", y, (y * y + 1), n);
        y = ((y * y + 1) % n);
        printf("g(y) = %d^2 + 1 = %d mod %d \n", y, (y * y + 1), n);
        resultadoY = y = ((y * y + 1) % n);
        printf("Resultado: %d \n", resultadoY);

        printf("\n");
        printf("|%d - %d| mod %d \n", x, y, n);
        printf("\n");      
        d = MDC(n, abs(x - y));
        printf("Resultado: %d \n", d);
        printf("\n");

        if (d == n){
            printf("Falha na itercao %d: d == n \n", iteracao);
            return -1; //Erro que não deveria acontecer
        }
    }
    return d;
}
//=================================================================
//Algoritmo extendido de Euclides
int Algoritmo_Estendido_De_Euclides(int a, int b, int *x, int *y){
    //Caso onde se b = 0; mdc(a, b) = a
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    //Passo Recursivo
    int x2, y2;
    int mdc = Algoritmo_Estendido_De_Euclides(b, a % b, &x2, &y2);

    printf("\n");
    printf("Calculando coeficientes para Algoritmo Estendido De Euclides( %d , %d ):", a, b);

    *x = y2;
    *y = x2 - (a / b) * y2;

    printf("\n");
    printf("%d - (%d/%d)*%d = %d", x2, a, b, y2, *y);

    return mdc;
}
//=================================================================
//Inverso Modular
int Inverso_Modular(int e, int z){
    int x, y;

    printf("\n");
    printf("Iniciando Inverso Modular \n");
    printf("Aplicando primeiro o Algoritmo Estendido de Euclides \n");
    printf("\n");

    int mdc = Algoritmo_Estendido_De_Euclides(e, z, &x, &y);
    
    printf("\n");
    printf("Resultado: mdc = %d, x = %d, y = %d \n", mdc, x, y);
    int d = (x % z + z) % z;

    printf("Ajustando para D ser positivo: D = (%d %% %d + %d) %% %d = %d \n", x, z, z, z, d);
    return d;
}
//=================================================================
//Pré-Codificação
int Pre_Codificacao(char caracter){
    if (caracter >= 'A' && caracter <= 'Z') return 11 + (caracter - 'A');
    else if (caracter == ' ') return 0;
    else if (caracter >= 'a' && caracter <= 'z') return 11 + (caracter - 'a');  
    else return -1; 
}
//=================================================================
//Decodificador
char Decodificador(int codigo){
    if (codigo == 0) return ' ';
    else return 'A' + (codigo - 11); 
}
//=================================================================
int Exponenciacao_Modular(int base, int expoente_original, int modulo, int totiente_z) {
    printf("\nCalculando %d^%d mod %d:\n", base, expoente_original, modulo);

    if (base == 0) {
        printf("Base eh 0, o resultado eh 0.\n");
        return 0;
    }

    int expoente = expoente_original;

    // Seleção automática do método de redução de expoente
    if (primo(modulo)) {
        printf("\n Aplicando Pequeno Teorema de Fermat, pois n = %d eh primo.\n", modulo);
        expoente = expoente_original % (modulo - 1);
        if (expoente == 0) expoente = modulo - 1;
        printf("Expoente reduzido: %d mod %d = %d\n", expoente_original, modulo - 1, expoente);
    } else if (MDC(base, modulo) == 1) {
        printf("\n Aplicando Teorema de Euler, pois mdc(%d, %d) = 1.\n", base, modulo);
        expoente = expoente_original % totiente_z;
        if (expoente == 0) expoente = totiente_z;
        printf("Expoente reduzido: %d mod %d = %d\n", expoente_original, totiente_z, expoente);
    } else {
        printf("\n Aplicando Teorema da Divisao Euclidiana (caso geral).\n");
    }

    int resultado = 1;
    int potencia_atual = base % modulo;
    int passo = 1;
    int temp_expo = expoente;

    while(temp_expo > 0) {
        printf("\nPasso %d:\n", passo++);
        if(temp_expo % 2 == 1) {
            printf("Expoente (%d) impar ->>> resultado = (%d * %d) mod %d = ", temp_expo, resultado, potencia_atual, modulo);
            resultado = (resultado * potencia_atual) % modulo;
            printf("%d\n", resultado);
        }
        temp_expo = temp_expo / 2;
        if (temp_expo == 0) break;
        printf("Atualizando potencia: (%d * %d) mod %d = ", potencia_atual, potencia_atual, modulo);
        potencia_atual = (potencia_atual * potencia_atual) % modulo;
        printf("%d\n", potencia_atual);
    }
    
    return resultado;
}
//=================================================================
int main(){
    printf("+=========================================+ \n");
    printf("|Pedro Lucas Barbosa da Silva - 241025710 | \n"); 
    printf("+=========================================+ \n");

    printf("\n");
    printf("Etapa 1 - Fatoracao Interativa (Metodo ρ de Pollard) \n");
    printf("Entrada de dados - inicializacao das variaveis \n");
    printf("\n");

    int N1, N2;
do {
    printf("*Aviso: o Metodo ρ de Pollard eh mais eficiente quando cada Ni eh produto primos distintos (semiprimos).* \n");
    printf("Insira dois numeros compostos 'a' e 'b' entre 100 e 9999: ");
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

    int p = pollard_rho(N1);
    int cofatorN1; // 1. Declara a variável do segundo cofator de N1
    if (p != 0) cofatorN1 = N1 / p; // 2. Se p não for zero, calcula a divisão 
        else cofatorN1 = 0;      // 3. Senão, atribui 0 para segurança
    if (p <= 1 || p == cofatorN1 || cofatorN1 <= 1 || !primo(cofatorN1) || !primo(p)){
        printf("Erro: O N1: %d nao atende aos requisitos, possuir produto de primos distintos. Os fatores obtidos foram: %d e %d \n", N1, p, cofatorN1);
        return 1;
    }

    int q = pollard_rho(N2);
    int cofatorN2; // 1. Declara a variável do segundo cofator de N1
    if (q != 0) cofatorN2 = N2 / q; // 2. Se p não for zero, calcula a divisão 
        else cofatorN2 = 0;      // 3. Senão, atribui 0 para segurança
    if (q <= 1 || q == cofatorN2 || cofatorN2 <= 1 || !primo(cofatorN2) || !primo(q)){
        printf("Erro: O N2: %d nao atende aos requisitos, possuir produto de primos distintos. Os fatores obtidos foram: %d e %d \n", N2, q, cofatorN2);
        return 1;
    }
    printf("\n");
    printf("Fatores Primos p e q encontrados: \n");
    printf("p = %d \n", p);
    printf("q = %d \n", q);
    printf("\n");

    printf("Etapa 2 - Geracao das Chaves RSA \n");
    printf("Construir o par de chaves publica e privada do sistema RSA \n");
    printf("\n");

    int n = p*q;
    int z = (p-1)*(q-1);
    printf("Sabemos que para calcular o modulo precisamos multiplicar os fatores primos %d e %d que encontramos anteriormente. \n", p, q);
    printf("\n");
    printf("Com isso e aplicando a formula (n = p x q), nosso modulo: \n");
    printf("n = %d", n);
    printf("\n");

    printf("Seguindo essa mesma logica podemos descobrir nosso Totiene de Euler (z(n) = (p-1)x(q-1)) \n");
    printf("\n");
    printf("Tendo assim nosso Totiene de Euler 'z' = %d \n", z);
    printf("\n");

    //Escolha do expoente Público
    printf("Escolha do Expoente Publico 'e' sabendo que (e >1 e e< n  tal que mdc (e, z(n))=1) \n");
    printf("Comecamos com menor primo possivel que e'2' \n");
    printf("\n");
    int e = 0;
    int D = 0;
    for(int i = 2; i < z; i++){
        if(MDC(z, i) == 1){
        e = i;
        printf("\n");
        printf("Expoente publico 'e' escolhido: %d \n", e);
        printf("\n");
        break;
        }
        printf("\n");
        printf("Enquanto nosso resto != 1 continuaremos a nossa busca \n");
    }
    //Escolha do expoente Privado
    printf("Passo de agora, encontrar o Expoente Privado 'D' sabendo que (D x e ≡ 1 mod z) \n");
    printf("Utilizando o Invero Modular para descobrir nosso 'D' \n");

    D = Inverso_Modular(e, z);

    printf("\n");
    printf("Expoente privado 'D' escolhido: %d \n", D);
    printf("\n");
    printf("Verificacao: (D x e) mod z = (%d x %d) mod %d = %d \n", D, e, z, (D * e) % z);
    printf("\n");

    printf("Chaves RSA geradas: \n");
    printf("Chave publica: (%d, %d) \n", n, e);
    printf("Chave privada: (%d, %d) \n", n, D);
    printf("\n");

    printf("Etapa 3 - Codificacao (Criptografia) e Decodificacao (Descriptografia)\n");
    printf("\n");

    char mensagem[1001];
    printf("Digite a mensagem para Criptografar: ");
    while(getchar() != '\n'); 
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = 0;

    printf("\n");
    printf("Pre-Codificacao \n");
    printf("\n");

    // Mostrar passo a passo da pré-codificação
    printf("Caracter ->> Codigo\n");
    printf("------------------\n");
    char preCodificado[5000];
    preCodificado[0] = '\0';

    for (int i = 0; mensagem[i] != '\0'; i++) {
        char c = mensagem[i];
        int codigo = Pre_Codificacao(c);
        if (codigo == -1) {
            printf("'%c' ->> Caracter invalido (ignorado)\n", c);
            continue;
        }
        if (codigo == 0) { // espaços como '00'
            strcat(preCodificado, "00 ");
        } else {
            char buf[6];
            snprintf(buf, sizeof(buf), "%02d ", codigo); // garante 2 digitos
            strcat(preCodificado, buf);
        }
    }
    printf("\n");
    printf("Frase pre-codificada (sequencia de codigos): \n");
    printf("%s \n", preCodificado);
    printf("\n");

    printf("Codificacao \n");
    printf("\n");

    printf("Para cada bloco M, calculamos C ≡ M^%d mod %d \n", e, n);
    printf("\n");

    // Converter string de números pré-codificados para array de inteiros
    int mensagem_numerica[1000];
    int num_blocos = 0;
    char *token = strtok(preCodificado, " ");

    while(token != NULL) {
        mensagem_numerica[num_blocos++] = atoi(token);
        token = strtok(NULL, " ");
    }
    printf("Blocos da mensagem pre-codificada: \n");
    for(int i = 0; i < num_blocos; i++) { 
        printf("Bloco M[%d] = %d\n", i + 1, mensagem_numerica[i]);
    }
    printf("\n");
    printf("Calculando C ≡ M^e mod n para cada bloco: \n");
    printf("\n");
    int mensagem_cifrada[1000];
    for(int i = 0; i < num_blocos; i++) {
        printf("\nBloco M[%d] = %d:\n", i + 1, mensagem_numerica[i]);
        mensagem_cifrada[i] = Exponenciacao_Modular(mensagem_numerica[i], e, n, z);
        printf("Resultado final: C[%d] = %d\n", i + 1, mensagem_cifrada[i]);
    }
    printf("\n");
    printf("Mensagem cifrada: \n");
    for(int i = 0; i < num_blocos; i++) {
        printf("%d ", mensagem_cifrada[i]);
    }
    printf("\n");

    // Etapa 3.5 - Decodificação
    printf("Etapa 3.5 - Decodificação (Descriptografia) \n");
    printf("\n");
    printf("Para cada bloco cifrado C, calculamos M ≡ C^%d mod %d\n", D, n);

    int mensagem_decifrada_numerica[1000];
    char mensagem_decodificada[1001] = "";

    for(int i = 0; i < num_blocos; i++) {
        printf("\n");
        printf("Bloco C[%d] = %d: \n", i + 1, mensagem_cifrada[i]);
        mensagem_decifrada_numerica[i] = Exponenciacao_Modular(mensagem_cifrada[i], D, n, z);
        char caracter_decodificado = Decodificador(mensagem_decifrada_numerica[i]);
        printf("Resultado final: M[%d] = %d ->>> Letra '%c' \n", i + 1, mensagem_decifrada_numerica[i], caracter_decodificado);
        
        char temp_str[2] = {caracter_decodificado, '\0'};
        strcat(mensagem_decodificada, temp_str);
    }
    printf("\n");
    printf("Mensagem decodificada final: \n");
    printf("%s \n", mensagem_decodificada);
    printf("\n");

    printf("Encerrando o programa \n");
    return 0;
}