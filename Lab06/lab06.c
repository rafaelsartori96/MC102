#include <stdio.h>

/*
 * Rafael Sartori Martins dos Santos (RA: 186154)
 */
int main() {
    int tempo, combustivelNecessario;

    // Recebendo valores de tempo e combustível
    scanf("%d %d", &tempo, &combustivelNecessario);

    int combustivel = 0;
    for(int i = 0; i < tempo; i++) {
        int j;
        // Recebendo a variação de combustível
        scanf("%d", &j);

        // Variando combustível
        combustivel += j;

        if(combustivel >= combustivelNecessario) {
            printf("sim\n%d\n", i + 1); // ele foge no próximo tempo (não imediatamente)
            return 0;
        }
    }

    printf("nao\n%d\n", tempo + 1);
}
