#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Entrada: 
 *          string_ordenada: a string original, que devemos processar 
 *                           para encontrarmos todos os anagramas
 *          letra_usada: um vetor de booleanos (implementado da forma 
 *                       de um vetor de inteiros) para marcarmos quais 
 *                       posições da string original já foram usadas
 *          word: o anagrama que estamos formando
 *          n: o numero de letras do anagrama
 *          k: a posição onde incluiremos a proxima letra em word
 * 
 * A ideia para gerar sem repeticoes eh que setada a letra da posicao k,
 * e retornado da chamada recursiva, temos
 * que colocar uma letra diferente na posição k, pois senão geraríamos
 * as repetições. Quando n==k incluimos a letra faltante e imprimimos o
 * anagrama.
 */
void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k){
  printf("%s\n",word);
  return;
}
