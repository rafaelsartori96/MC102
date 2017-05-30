#include <stdio.h>
#include <stdlib.h>
// Deve ser compilado com "-lm"
#include <math.h>


double media(double *vetor, int tamanho) {
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma / tamanho;
}

// Não é o desvio padrão populacional
double desvioPadrao(double *vetor, int tamanho) {
    double soma = 0, x_media = media(vetor, tamanho);
    for(int i = 0; i < tamanho; i++) {
        double x = x_media - vetor[i];
        soma += x * x;
    }
    return sqrt(soma / (tamanho - 1));
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
        scanf("%lf", &vetor[i]);
    }

    printf(
        "A média é %.2lf e o desvio padrão é %.2lf.\n",
        media(vetor, tamanho),
        desvioPadrao(vetor, tamanho)
    );
}
