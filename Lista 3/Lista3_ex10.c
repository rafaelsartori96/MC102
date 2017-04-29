#include <stdio.h>

int min(int a, int b) {
    if(a > b)
        return b;
    else
        return a;
}

int coprimos(int a, int b) {
    // Inclui todos os divisores, inclusive o próprio número
    for(int i = 2; i <= min(a, b); i++) {
        if((a % i) == 0 && (b % i) == 0)
            return 0;
    }
    // Não encontramos um divisor de a que é divisor de b, logo, são coprimos.
    return 1;
}

int main() {
    int tamanho;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Entre com o vetor: ");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    for(int linha = -1; linha < tamanho; linha++) {
        for(int coluna = -1; coluna < tamanho; coluna++) {
            // Linha de índices
            if(linha == -1) {
                if(coluna == -1) {
                    printf("    ");
                } else {
                    printf("    v[%d]", coluna);
                }
            } else {
                // Coluna de índices
                if(coluna == -1) {
                    printf("v[%d]", linha);
                } else {
                    int saoCoprimos = coprimos(vetor[linha], vetor[coluna]);
                    if(linha == coluna)
                        saoCoprimos = 0;
                    printf("       %d", saoCoprimos);
                }
            }
        }
        printf("\n");
    }
}
