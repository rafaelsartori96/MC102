// Rafael Sartori Martins dos Santos (RA: 186154)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Entrada:
 *          string_ordenada: a string original, que devemos processar para encon-
 *                           trarmos todos os anagramas
 *          letra_usada: um vetor de booleanos (implementado da forma de um vetor
 *                       de n inteiros) para marcarmos quais posições da string
 *                       original já foram usadas
 *          word: o anagrama que estamos formando
 *          n: o numero de letras do anagrama
 *          k: a posição onde incluiremos a proxima letra em word
 *
 * A ideia para gerar sem repeticoes é que setada a letra da posicao k, e retor-
 * nado da chamada recursiva, temos que colocar uma letra diferente na posição k,
 * pois senão geraríamos as repetições. Quando n==k incluimos a letra faltante e
 * imprimimos o anagrama
 */
void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k) {
    // k é o índice que devemos colocar a letra, se chegamos em n, significa que
    // devemos colocar o \0 e imprimir
    if(k == n) {
        // Se chegamos ao final da string, terminamos e imprimimos
        *(word + k) = '\0';
        printf("%s\n", word);
    } else {
        /*
         * Ao contrário de algumas pessoas e do pseudocódigo divulgado segunda-
         * -feira, eu criei um vetor adicional (mais ineficiente em questões de
         * memória), poderia ter apenas conferido *(word + k) anterior, mas não
         * pensei nisso, pois tentava conferir (string_ordenada + k - 1), sem
         * sucesso.
         */
        char *letra_usada_k = malloc(n * sizeof(char));
        int letra_usada_tam = 0;
        if(letra_usada_k == NULL) {
            printf("Erro ao alocar memória dinâmica.\n");
            return;
        }

        // Como não estamos no final da string, temos de iterar entre as letras
        // não usadas
        for(int pos = 0; pos < n; pos++) {
            // printf("conferindo k = %d, pos = %d\n", k, pos);
            // Pularemos letras já usadas
            if(*(letra_usada + pos) == 1)
                continue;

            int pularemos = 0;
            for(int i = 0; i < letra_usada_tam; i++) {
                // Pularemos letras que já foram usadas nessa posição
                if(*(string_ordenada + pos) == *(letra_usada_k + i)) {
                    pularemos = 1;
                    break;
                }
            }
            if(pularemos)
                continue;

            // printf("k = %d, pos = %d\n", k, pos);

            // Marcaremos a letra como usada e a colocamos no índice k de word
            *(letra_usada + pos) = 1;
            *(word + k) = *(string_ordenada + pos);
            *(letra_usada_k + (letra_usada_tam++)) = *(string_ordenada + pos);
            generate(string_ordenada, letra_usada, word, n, k + 1);

            // Agora que já usamos a letra e ela deve ter sido impressa em
            // instâncias menores de 'generate', podemos colocá-la como não
            // utilizada
            *(letra_usada + pos) = 0;
        }

        // Liberaremos a lista de letras usadas em k
        free(letra_usada_k);
    }
}
