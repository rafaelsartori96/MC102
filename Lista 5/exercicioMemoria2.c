#include <stdio.h>
#include <stdlib.h>

#define SIZE 100


/**
 * Exercício: free no meio do vetor
 *
 * Resultado: não é possível usar free em um endereço que pertence a um bloco
 * alocado.
 */
int main() {
    printf("Alocando vetor dinâmico...");
    int *vetor;
    vetor = malloc(SIZE * sizeof(int));
    if(vetor == NULL) {
        printf(" Não foi possível alocar o vetor!\n");
        return -1;
    }
    printf(" Sucesso!\n");

    // Inicializando o vetor
    for(int i = 0; i < SIZE; i++) {
        vetor[i] = i + 1;
    }

    // printf("Liberando &vetor[SIZE / 2]...");
    // free(&vetor[SIZE / 2]);
    // printf(" Sucesso!\n");

    for(int i = 0; i < SIZE; i++) {
        if(i >= SIZE / 2)
            printf("-");
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("Liberando vetor...");
    free(vetor);
    printf(" Sucesso!\n");
    return 0;
}
