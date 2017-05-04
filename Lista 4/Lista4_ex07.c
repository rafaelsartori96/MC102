#include <stdio.h>

int main() {
    printf("Entre com uma string de, no máximo, 1000 caracteres: ");

    char texto[1000], caractere;
    int indice = -1;
    do {
        scanf("%c", &caractere);
        if(caractere != '\n' && caractere != EOF) {
            // Apesar de não termos terminado de ler a entrada, temos que guar-
            // dar apenas letras
            if(caractere != ' ')
                texto[++indice] = caractere;
        } else {
            // Não alteramos o valor de indice pois precisamos saber qual foi
            // o último caractere
            texto[indice + 1] = '\n';
            texto[indice + 2] = '\0';
            break;
        }
    } while(1);

    // Vamos determinar se a string é um palíndromo:
    // Devemos conferir se o final é igual ao começo, parando na metade
    for(int i = indice, j = 0; i >= indice / 2; i--, j++) {
        if(texto[j] != texto[i]) {
            printf("O texto entrado não é um palíndromo!\n");
            return 0;
        }
    }
    printf("O texto entrado é um palíndromo.\n");
}
