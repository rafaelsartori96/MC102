//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int main(void) {
    unsigned int a;
    printf("== Testando unsigned int ==\nEntre um valor para 'a' de no máximo 4294967295: ");
    scanf("%u", &a);
    printf("Seu valor para 'a' foi %u, seu valor negativo convertido é %ld. Já seu valor não convertido é %u.", a,
           ((long int) (a) * (-1)), (-a));
    return 0;
}
