# Codigos-MD2-Prova-2
Repositório destinádo com os códigos e resoluções da Prova 2 (Ponto Extra) da disciplina Matemática Discreta 2.
---
# Códigos

<h2 align="center"> Questão 1: Sistema RSA com Fatoração ρ de Pollard e Aplicação de Teoremas Modulares em Três Etapas.</h2>


<h2 align="center"> Questão 2: Chaves Periódicas. </h2>

<h2 align="center"> Questão 3: Razão de Eficiência de um Número. </h2>

<h2 align="center"> Questão 4 - Bônus</h2>
Após corrigir os trechos do Código, foi solicitado: <strong>Qual seria a saída com os valores: H: 7, G: 3, Zn: 11,  x: 10, n1: 13</strong>

#### Rodando o código com as informações solicitadas:

Insira H: 7
Insira G: 3
Insira Zn: 11
Insira x: 10
Insira n1: 13

Algoritmo de Euclides: 3 mod 11 = 3
Algoritmo de Euclides: 11 mod 3 = 2
Algoritmo de Euclides: 3 mod 2 = 1
Algoritmo de Euclides: 2 mod 1 = 0

Substituindo, temos que o inverso de 3 em 11 é 4.

Fazendo a multiplicacao modular: 7 * 4 mod 11 = 6
  Sendo 4 o inverso de 3.
Valor final da congruencia: 4

Resposta final = 4
---
### Perguntas de V ou F

- { V } O algoritmo de Euclides estendido é utilizado para calcular o inverso modular de um número.
- { F } Se mdc(G, Zn) ≠ 1, o programa ainda consegue encontrar o inverso de G em Zn
- { V } A operação (H * inverso) % Zn representa a divisão modular de H por G.
- { V } Se n1 for primo, o código aplica o Pequeno Teorema de Fermat para simplificar o cálculo de
 a^x mod n1.
 - { F } A função powMod implementa o cálculo de potência modular utilizando multiplicações diretas
 sem otimização.
 - { V } Quando o resultado do inverso é negativo, o código ajusta o valor somando o módulo m0.
 - { F } O cálculo de fi(n1) (função totiente de Euler) é utilizado apenas quando n1 não é primo

---
## 👤 Autor


<table align="center">
  <tr>
    <td align="center">
      <img src="./Imagem/p5.jpg" width="100"><br>
      <b><a href="https://github.com/Pwdrinho" style="text-decoration: none; color: white;"> 🍎 Pedro Lucas 🍊</a></b><br>
      241025710
    </td>
  </tr>
</table>