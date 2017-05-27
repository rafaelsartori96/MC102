#include <stdio.h>
#include <stdlib.h>

#define TESTES 5


int GLOBAL_VAR = 0;

void testStack(int i) {
    int var1, var2;
    printf("Os endereços de var1 e var2 são %lu e %lu\n", (unsigned long int) &var1,
        (unsigned long int) &var2);
    int *pointer;
    pointer = malloc(sizeof(int));
    printf("O endereço de pointer é %lu\n", (unsigned long int) pointer);
    printf("\n");
    if(i > 0)
    testStack(--i);
    free(pointer);
}

/**
 * Exercício: verificar se a heap (espaço destinado à memória alocada dinâmica-
 * mente) cresce do fim da memória para o início (endereço zero) ou o stack.
 *
 * Resultado: a memória do stack fica no fim da memória, crescendo para cima.
 * enquanto a heap cresce do início para o fim. O código fica antes da heap. E
 * as variáveis globais ficam entre o código e a heap.
 *
 * Logo, a sequência da memória fica:
 * - Código
 * - Variáveis globais
 * - Heap
 * - Stack (de baixo para cima)
 */
int main() {
    testStack(TESTES);
    printf("O endereço da função testStack é %lu\n", (unsigned long int) &testStack);
    printf("O endereço de GLOBAL_VAR é %lu\n", (unsigned long int) &GLOBAL_VAR);
}
