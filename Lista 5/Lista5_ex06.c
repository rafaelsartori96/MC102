#include <stdio.h>
#include <stdlib.h>


double media(double *vetor, int tamanho) {
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma / tamanho;
}

int main() {
    int tamanho;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);

    double *vetor = NULL;
    vetor = malloc(tamanho * sizeof(double));
    if(vetor == NULL) {
        printf("Não foi possível alocar o vetor.\n");
        return -1;
    }

    printf("Entre com os valores: ");
    for(int i = 0; i < tamanho; i++) {
        double valor;
        scanf("%lf", &valor);
        vetor[i] = valor;
    }

    printf("A média é %.3lf.\n", media(vetor, tamanho));
}
