#include <stdio.h>

int main() {
    int tamanho1, tamanho2;
    printf("Encontraremos o número de ocorrências da primeira sequência de números inteiros na segunda sequência, onde a segunda sequência é maior.\nEntre com o tamanho da primeira sequência: ");
    scanf("%d", &tamanho1);
    printf("Entre com os valores da primeira sequência: ");
    int sequencia1[tamanho1];
    for(int i = 0; i < tamanho1; i++) {
        scanf("%d", &sequencia1[i]);
    }

    printf("Entre com o tamanho da segunda sequência: ");
    scanf("%d", &tamanho2);
    printf("Entre com os valores da segunda sequência: ");
    int sequencia2[tamanho2];
    for(int i = 0; i < tamanho2; i++) {
        scanf("%d", &sequencia2[i]);
    }

    int contido = 0;
    // Agora faremos um loop na segunda sequência, de zero até a última possível
    // posição para a segunda sequência
    for(int i = 0; i < (tamanho2 - tamanho1); i++) {
        int iguais = 1;
        for(int j = 0; j < tamanho1; j++) {
            if(sequencia1[j] != sequencia2[i + j]) {
                iguais = 0;
                break;
            }
        }

        if(iguais)
            contido++;
    }

    printf("A sequência 1 está contida na sequência 2 %d vezes.\n", contido);
}
