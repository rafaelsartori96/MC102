#include <stdio.h>

int main() {
    int tamanho1, tamanho2;
    printf("Faremos a intersecção entre duas sequências de números inteiros.\nEntre com o tamanho da primeira sequência: ");
    scanf("%d", &tamanho1);
    int sequencia1[tamanho1];
    printf("Entre com a primeira sequência: ");
    for(int i = 0; i < tamanho1; i++) {
        scanf("%d", &sequencia1[i]);
    }

    printf("Entre com o tamanho da segunda sequência: ");
    scanf("%d", &tamanho2);
    int sequencia2[tamanho2];
    printf("Entre com a segunda sequência: ");
    for(int i = 0; i < tamanho2; i++) {
        scanf("%d", &sequencia2[i]);
    }

    int interseccao[tamanho1 + tamanho2];
    int tamanho = 0;

    for(int i = 0; i < tamanho1; i++) {
        int elementoEstaNaSeq2 = 0;
        for(int j = 0; j < tamanho2; j++) {
            if(sequencia1[i] == sequencia2[j]) {
                elementoEstaNaSeq2 = 1;
                break;
            }
        }

        if(elementoEstaNaSeq2)
            interseccao[tamanho++] = sequencia1[i];
    }

    printf("Intersecção: {");
    for(int i = 0; i < tamanho; i++) {
        if(i > 0)
            printf(", ");
        printf("%d", interseccao[i]);
    }
    printf("}\n");
}
