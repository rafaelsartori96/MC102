//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int main(void) {
    char type;
    float temperature;

    printf("Digite o tipo de temperatura dada (F para Fahrenheit, C para Celsius): ");
    scanf("%c", &type);

    if (!(type == 'c' || type == 'C' || type == 'f' || type == 'F')) {
        printf("Tipo não reconhecido!\n");
        return -1;
    }

    printf("Entre a temperatura: ");
    scanf("%f", &temperature);

    printf("A temperatura em graus ");
    if (type == 'c' || type == 'C')
        printf("Fahrenheit é %.3lfºF\n", ((9.0 / 5) * temperature) + 32);
    else if (type == 'f' || type == 'F')
        printf("Celsius é %.3lfºC.\n", (5 / 9.0) * (temperature - 32));

    return 0;
}