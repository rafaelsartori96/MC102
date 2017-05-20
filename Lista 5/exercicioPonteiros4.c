#include <stdio.h>
#include <stdlib.h>

/**
 * Exercício: alocar e utilizar um vetor v1, guardar o endereço apontado em v2,
 * e conferir o vetor v2 depois de liberar v1
 *
 * Resultado: alguns elementos foram modificados, outros permaneceram iguais.
 */
int main() {
    int *v1, *v2, tamanho;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);

    printf("Alocando vetor... ");
    v1 = malloc(tamanho * sizeof(int));
    if(v1 == NULL) {
        printf("Não foi possível alocar o vetor!\n");
    } else {
        printf("Vetor alocado com sucesso em %p!\n", v1);
        // Inicializando v1
        for(int i = 0; i < tamanho; i++) {
            v1[i] = i + 1;
            printf("v1[%d] = %d\n", i, v1[i]);
        }
        // Colocando o endereço apontado por v1 em v2
        v2 = v1;
        // Liberando v1
        printf("Liberando v1...\n");
        free(v1);
        for(int i = 0; i < tamanho; i++)
            printf("v2[%d] = %d\n", i, v2[i]);
    }
}
