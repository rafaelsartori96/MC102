#include <stdio.h>

int main() {
    int dimensoes;
    printf("Calcularemos o produto interno (produto escalar) entre dois vetores. Entre com o número de dimensões: ");
    scanf("%d", &dimensoes);

    double vetor1[dimensoes], vetor2[dimensoes];
    printf("Entre com os valores do primeiro vetor: ");
    for(int i = 0; i < dimensoes; i++) {
        scanf("%lf", &vetor1[i]);
    }

    printf("Entre com os valores do segundo vetor: ");
    for(int i = 0; i < dimensoes; i++) {
        scanf("%lf", &vetor2[i]);
    }

    double soma = 0;
    for(int i = 0; i < dimensoes; i++) {
        soma += vetor1[i] * vetor2[i];
    }
    printf("O produto escalar entre os vetores é %.2lf.\n", soma);
}
