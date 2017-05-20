#include <stdio.h>
#include <stdlib.h>

/**
 * Exercício: Imprimir alguns elementos de vetores alocados com malloc e compa-
 * rar com calloc. Além disso, usaremos a aritmética de ponteiros para conferir
 * o valor do vetor nos índices.
 *
 * Resultado: malloc e calloc deram o mesmo resultado, todos os caracteres eram
 * \0. A aritmética dos ponteiros funciona como vetores normais, a própria lin-
 * guagem de programação pula os bytes necessários para os tipos do ponteiro,
 * ou seja, você usa apenas (ponteiro + 1...n), não (ponteiro + (1...n)*sizeof).
 */
int main() {
    char *p_malloc, *p_calloc;

    int tamanhoVetor;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    printf("Alocando com malloc... ");
    p_malloc = malloc(tamanhoVetor * sizeof(char));
    if(p_malloc == NULL) {
        printf("Vetor não pôde ser alocado.\n");
    } else {
        printf("Vetor alocado com sucesso!\n");
        for(int i = 0; i < tamanhoVetor; i++) {
            printf("vetor[%d] = '%c'\n", i, *(p_malloc + i));
        }
        free(p_malloc);
    }

    printf("Alocando com calloc... ");
    p_calloc = calloc(tamanhoVetor, sizeof(char));
    if(p_calloc == NULL) {
        printf("Vetor não pôde ser alocado.\n");
    } else {
        printf("Vetor alocado com sucesso!\n");
        for(int i = 0; i < tamanhoVetor; i++) {
            printf("vetor[%d] = '%c'\n", i, *(p_calloc + i));
        }
        free(p_calloc);
    }
}
