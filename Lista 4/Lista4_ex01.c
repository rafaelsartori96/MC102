#include <stdio.h>
#include <string.h>

int main() {
    char string[80], stringInvertida[80];

    printf("Entre com um texto de no máximo 80 caracteres:\n");
    fgets(string, 80, stdin);

    int index = 0;
    // Devemos iniciar de (strlen(string) - 2) pois (strlen(string) - 1) será
    // o '\n' que não desejamos inverter.
    for(int i = strlen(string) - 2; i >= 0; i--) {
        stringInvertida[index++] = string[i];
    }
    // Terminar com '\n\0'
    stringInvertida[index++] = '\n';
    stringInvertida[index] = '\0';

    printf("O texto invertido é:\n%s", stringInvertida);
}
