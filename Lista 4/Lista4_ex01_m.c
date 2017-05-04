#include <stdio.h>
#include <string.h>

int main() {
    char string[80];

    printf("Entre com um texto de no máximo 80 caracteres:\n");
    fgets(string, 80, stdin);

    int index = 0;
    char auxiliar;
    // Devemos iniciar de (strlen(string) - 2) pois (strlen(string) - 1) será
    // o '\n' que não desejamos inverter.
    for(int i = strlen(string) - 2; i >= ((strlen(string) / 2) + 1); i--) {
        auxiliar = string[index];
        string[index++] = string[i];
        string[i] = auxiliar;
    }

    printf("O texto invertido é:\n%s", string);
}
