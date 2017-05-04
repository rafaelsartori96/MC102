#include <stdio.h>

int main() {
    int lado;
    printf("Entre com o tamanho do quadrado: ");
    scanf("%d", &lado);

    for(int i = 1; i < lado; i++) {
        if(i * i == lado) {
            lado = i;
            break;
        }
    }

    char matriz[lado][lado + 1];
    printf("Entre com a mensagem oculta: ");

    int i = 0, j = 0;
    char caractere;
    do {
        scanf("%c", &caractere);
        if(caractere != '\n' && caractere != EOF) {
            matriz[i][j++] = caractere;
            if(j >= lado) {
                matriz[i++][j] = '\0';
                j = 0;
            }
        }
    } while(i < lado);

    printf("A mensagem decodificada é:\n");
    for(int linha = 0; linha < lado; linha++) {
        for(int coluna = 0; coluna < lado; coluna++) {
            if(coluna > 0)
                printf(" ");
            printf("%c", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
