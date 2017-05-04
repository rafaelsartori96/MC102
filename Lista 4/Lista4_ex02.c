#include <stdio.h>
#include <string.h>

// Já fiz a segunda parte do exercício pois achei mais fácil
int main() {
    char string[80], caractere;
    int index = 0;

    printf("Entre com o texto de no máximo 80 caracteres a ser modificado:\n");
    do {
        scanf("%c", &caractere);
        if(caractere != ' ' && caractere != '\n' && caractere != EOF)
            string[index++] = caractere;
    } while(caractere != '\n' && caractere != EOF);
    // Terminando a string
    string[index++] = '\n';
    string[index] = '\0';
    printf("%s", string);
}
