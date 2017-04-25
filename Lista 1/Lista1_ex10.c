//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int main(void) {
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    // Primeiro ano
    printf("Digite o dia do primeiro ano: ");
    scanf("%d", &dia1);
    printf("Digite o mês do primeiro ano: ");
    scanf("%d", &mes1);
    printf("Digite o ano do primeiro ano: ");
    scanf("%d", &ano1);
    // Segundo ano
    printf("Digite o dia do segundo ano: ");
    scanf("%d", &dia2);
    printf("Digite o mês do segundo ano: ");
    scanf("%d", &mes2);
    printf("Digite o ano do segundo ano: ");
    scanf("%d", &ano2);

    if (ano1 > ano2) {
        printf("O primeiro ano é mais recente!\n");
    } else if (ano1 == ano2) {
        if (mes1 > mes2) {
            printf("O primeiro ano é mais recente!\n");
        } else if (mes1 == mes2) {
            if (dia1 > dia2) {
                printf("O primeiro ano é mais recente!\n");
            } else if (dia1 == dia2) {
                printf("Os anos são iguais!\n");
            } else {
                printf("O segundo ano é mais recente!\n");
            }
        } else {
            printf("O segundo ano é mais recente!\n");
        }
    } else {
        printf("O segundo ano é mais recente!\n");
    }
    return 0;
}
