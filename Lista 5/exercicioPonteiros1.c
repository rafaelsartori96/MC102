#include <stdio.h>
#include <stdlib.h>

/**
 * Exercício: comparar o uso de grandes vetores declarados através de uma variá-
 * vel (será alocado numa pilha) ou através de malloc(bytes)
 *
 * Resultado: alocando 8gb em memória dinâmica não deu problema algum (exceto
 * a lentidão para tentar fechar o programa, pois só tenho 6gb de RAM, ou seja,
 * usei o swap - na verdade eu havia errado na conta, meu plano era 1GB hahaah)
 */
int main() {
    long int tamanhoVetor;
    printf("Entre com o tamanho do vetor de inteiros (%dx%d = 1024 bytes ou 1 kB): ", (1024 / sizeof(long int)), sizeof(long int));
    scanf("%ld", &tamanhoVetor);

    printf("Declarando usando malloc...");
    long int *p_vetor = malloc(tamanhoVetor * sizeof(long int));
    if(p_vetor == NULL)
        printf(" O vetor não pôde ser alocado. D:\n");
    else
        printf(" O vetor de %ld MB foi alocado com sucesso em %p! :)\n",
                    ((tamanhoVetor * sizeof(long int)) / (1024 * 1024)), p_vetor);

    for(long int i = 0; i < tamanhoVetor; i++) {
        p_vetor[i] = i;
    }

    printf("Digite 'g' para testarmos o vetor em pilha.\n");
    char entrada;
    do {
        scanf("%c", &entrada);
    } while(entrada != 'g');

    if(p_vetor != NULL)
        free(p_vetor);

    printf("Declarando usando vetor[variável]...");
    int vetor[tamanhoVetor];
    printf(" O vetor foi criado com sucesso!\n");
}
