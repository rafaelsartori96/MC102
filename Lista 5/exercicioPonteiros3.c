#include <stdio.h>
#include <stdlib.h>

/**
 * Exercício: Imprimindo um "%d" ao invés de "%p" de um ponteiro
 *
 * Resultado: o resultado foi igual, porém deve não funcionar para endereços
 * que necessitam de um long int para serem representados como decimais.
 * Saída: ponteiro: 0xd3e010, inteiro: 13885456
 * porém "0xd3e010" em hexadecimal é transformado para "13885456" em decimal
 */
int main() {
    int *ponteiro;
    ponteiro = malloc(sizeof(int));
    if(ponteiro != NULL) {
        printf("ponteiro: %p, inteiro: %d\n", ponteiro, ponteiro);
        free(ponteiro);
    }
}
