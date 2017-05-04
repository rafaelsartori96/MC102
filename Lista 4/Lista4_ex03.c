#include <stdio.h>
#include <string.h>

int main() {
    char string[80], caractere;
    int index = 0;

    printf("Entre com o texto de no máximo 80 caracteres a ser modificado:\n");
    do {
        scanf("%c", &caractere);
        if(caractere != '\n' && caractere != EOF && (caractere != ' ') ||
            (caractere == ' ' && (index == 0 || string[index - 1] != ' ')))
            string[index++] = caractere;
    } while(caractere != '\n' && caractere != EOF);
    // Terminando a string
    string[index++] = '\n';
    string[index] = '\0';
    printf("%s", string);
}
