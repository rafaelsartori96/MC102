#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int valor;
    unsigned int ocorrencias;
} Elemento;


/*
 * Retorna uma referência ao elemento, ou NULL caso ele não esteja no vetor.
 */
Elemento *posicaoElemento(Elemento *elementos, unsigned int tamanho, int valor) {
    for(unsigned int i = 0; i < tamanho; i++) {
        // Caso os valores desses endereços sejam iguais, retornamos a posição
        // do elemento no vetor elementos
        if((elementos + i)->valor == valor) {
            return (elementos + i);
        }
    }
    return NULL;
}

/*
 * Precisamos de ponteiro para ponteiro de elemento pois iremos alterar o valor
 * para qual o ponteiro aponta
 */
void conferirFrequencias(Elemento *elemento, Elemento **maiorFreq, Elemento **menorFreq) {
    // Conferimos a maior frequência
    if((*maiorFreq) == NULL || elemento->ocorrencias > (*maiorFreq)->ocorrencias)
        *maiorFreq = elemento;

    // Conferimos a menor frequência
    if((*menorFreq) == NULL || elemento->ocorrencias < (*menorFreq)->ocorrencias)
        *menorFreq = elemento;
}

int frequencias(int *vetor, unsigned int tamanho, int *menorFrequencia, int *maiorFrequencia) {
    Elemento *elementos = malloc(tamanho * sizeof(Elemento));
    unsigned int tamanhoElementos = 0;
    if(elementos == NULL) {
        printf("Erro ao alocar memória dinâmica.\n");
        return 0;
    }

    Elemento *menorFreq = NULL, *maiorFreq = NULL;

    for(unsigned int i = 0; i < tamanho; i++) {
        Elemento *elemento = posicaoElemento(elementos, tamanhoElementos, *(vetor + i));

        if(elemento != NULL) {
            // Caso o elemento foi encontrado, incrementamos suas ocorrências
            elemento->ocorrencias++;

            conferirFrequencias(elemento, &maiorFreq, &menorFreq);
        } else {
            // Caso o elemento não foi encontrado,
            elemento = (elementos + (tamanhoElementos++));
            // Adicionamos o elemento no vetor elementos
            elemento->valor = *(vetor + i);
            elemento->ocorrencias = 1;

            conferirFrequencias(elemento, &maiorFreq, &menorFreq);
        }
    }

    *maiorFrequencia = maiorFreq->valor;
    *menorFrequencia = menorFreq->valor;

    free(elementos);
    return 1;
}

int main() {
    unsigned int tamanho;
    printf("Entre com o tamanho do vetor: ");
    scanf("%u", &tamanho);

    int *vetor = malloc(tamanho * sizeof(int));
    if(vetor == NULL) {
        fprintf(stderr, "Erro ao alocar memória dinâmica!\n");
        return 1;
    }

    printf("Entre com os elementos do vetor:\n");
    for(unsigned int i = 0; i < tamanho; i++) {
        // Guardamos o valor no vetor[i]
        scanf("%d", (vetor + i));
    }

    int maiorFrequencia, menorFrequencia;
    // Conferimos se frequencias funcionou como o esperado
    if(!frequencias(vetor, tamanho, &menorFrequencia, &maiorFrequencia)) {
        return -2;
    }

    printf(
        "O elemento de maior frequência é %d, e o de menor, %d.\n",
        maiorFrequencia,
        menorFrequencia
    );

    free(vetor);
}
