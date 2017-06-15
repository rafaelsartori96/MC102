#include <stdio.h>
#include <stdlib.h>


double absolute(double value) {
    return value < 0 ? -value : value;
}

double media(double *vetor, int n, int *posicaoProxima) {
    double media = 0;
    for(int i = 0; i < n; i++) {
        // Somamos todos os itens
        media += *(vetor + i);
    }
    // Dividiremos por n para encontrar a média real
    media /= n;

    // Agora encontraremos a posição do elemento mais próximo da média
    int posicao = -1;
    double diferenca = -1;
    for(int i = 0; i < n; i++) {
        double diferenca_ = absolute(*(vetor + i) - media);
        // Se a posição mais próxima não está definida, ou se a diferença é
        // menor, substituimos o valor da posição e diferença
        if(posicao == -1 || diferenca_ < diferenca) {
            posicao = i;
            diferenca = diferenca_;
        }
    }
    // Atualizamos o valor passado por referência e retornamos a média
    *posicaoProxima = posicao;
    return media;
}

int main() {
    double *vetor = NULL, media_;
    int n, posicaoProxima;
    printf("Entre com o tamanho n do vetor: ");
    scanf("%d", &n);

    vetor = malloc(n * sizeof(double));
    if(vetor == NULL) {
        printf("Não foi possível alocar um vetor.\n");
        return 1;
    }

    printf("Entre com os valores:\n");
    for(int i = 0; i < n; i++) {
        scanf("%lf", (vetor + i));
    }

    media_ = media(vetor, n, &posicaoProxima);
    printf(
        "A média do vetor é %.2lf, e o elemento mais próximo é %.2lf.\n",
        media_,
        *(vetor + posicaoProxima)
    );
    free(vetor);
}
