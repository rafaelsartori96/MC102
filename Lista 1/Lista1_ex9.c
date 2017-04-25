//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    int ano;

    printf("Entre um ano: ");
    scanf("%d", &ano);

    // Bissexto = multiplo de 400 OU (multiplo de 4 e não multiplo de 100)
    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0))
        printf("O ano %d é bissexto.\n", ano);
    else
        printf("O ano %d não é bissexto. :/\n", ano);
    return 0;
}
