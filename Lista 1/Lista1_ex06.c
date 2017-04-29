//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int main(void) {
    int a;
    printf("Digite um número inteiro:");
    scanf("%d", &a);
    if ((a % 2 == 0)) {
        // Caso par
        if (a < 100)
            printf("O número é par e menor que 100\n");
        else
            printf("O número é par e maior ou igual a 100\n");
    } else {
        // Caso ímpar
        if (a < 100)
            printf("O número é ímpar e menor que 100\n");
        else
            printf("O número é ímpar e maior que 100\n");
    }
    return 0;
}