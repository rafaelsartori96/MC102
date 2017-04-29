#include <stdio.h>

int main() {
    int tamanho;
    printf("Vamos intercalar dois vetores ordenados de mesmo tamanho. Entre com o tamanho dos vetores: ");
    scanf("%d", &tamanho);
    int vetor1[tamanho], vetor2[tamanho];

    printf("Entre com os valores do primeiro vetor: ");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor1[i]);
    }
    printf("Entre com os valores do segundo vetor: ");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor2[i]);
    }

    int vetor3[2 * tamanho];
    int indice = 0, index1 = 0, index2 = 0;

    while (index1 < tamanho || index2 < tamanho) {
        // Controlando os extremos
        if(index1 >= tamanho) {
            vetor3[indice++] = vetor2[index2++];
            continue;
        } else if (index2 >= tamanho){
            vetor3[indice++] = vetor1[index1++];
            continue;
        }

        // Estamos em índices normais
        if(vetor1[index1] >= vetor2[index2]) {
            vetor3[indice++] = vetor2[index2++];
        } else {
            vetor3[indice++] = vetor1[index1++];
        }
    }

    printf("Vetor intercalado: {");
    for(int i = 0; i < 2 * tamanho; i++) {
        if(i > 0)
            printf(", ");
        printf("%d", vetor3[i]);
    }
    printf("}\n");
}
