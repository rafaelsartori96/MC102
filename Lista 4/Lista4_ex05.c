#include <stdio.h>
#include <string.h>

int main() {
    char caracteres[124], string[1000];

    printf("Entre com o texto, de no máximo 1000 caracteres: ");
    fgets(string, 1000, stdin);

    printf("Entre com os caracteres que deseja remover, não é necessário usar nenhum caractere para separá-los: ");
    char caractere;
    int indice = 0;
    do {
        scanf("%c", &caractere);
        if(caractere != '\n' && caractere != EOF) {
            caracteres[indice++] = caractere;
        }
    } while (caractere != '\n' && caractere != EOF);
    // Terminar com '\0'
    caracteres[indice] = '\0';

    printf("O texto com caracteres removidos é: ");
    // "i <= strlen(string)" pois queremos incluir o \n
    for(int i = 0; i < strlen(string); i++) {
        int proibido = 0;
        // Vamos vasculhar os caracteres e conferir se ele é permitido no texto
        for(int j = 0; j < indice; j++) {
            if(string[i] == caracteres[j]) {
                proibido = 1;
                break;
            }
        }

        if(!proibido)
            printf("%c", string[i]);
    }
}
