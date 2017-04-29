#include <stdio.h>

int main() {
    int tamanho;
    printf("Entre com o tamanho da lista a ser digitada: ");
    scanf("%d", &tamanho);

    int valor_anterior, valor;
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &valor);
        if(i > 0 && valor < valor_anterior) {
            printf("Sua lista não está ordenada!\n");
            return 0;
        }

        // Já que está ordenada até agora, continuaremos para o próximo número:
        valor_anterior = valor;
    }

    printf("A lista estava ordenada. ;)\n");
}
