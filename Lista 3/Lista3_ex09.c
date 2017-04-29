#include <stdio.h>

int main() {
    int tamanho, c;
    printf("Encontraremos o par de números no vetor inteiro tal que seu produto seja igual a C. Entre com o tamanho dos vetores: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    printf("Entre com o vetor: ");
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Entre com o valor do produto a ser encontrado: C = ");
    scanf("%d", &c);

    int produtoEncontrado = 0;
    for(int i = 0; i < tamanho; i++) {
        for(int j = i; j < tamanho; j++) {
            if(i == j) continue;
            if(vetor[i] * vetor[j] == c) {
                printf("%d * %d = %d\n", vetor[i], vetor[j], c);
                produtoEncontrado = 1;
            }
        }
    }

    if(!produtoEncontrado)
        printf("Não há valores cujo produto é possível.\n");
}
