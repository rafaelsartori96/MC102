//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    float x;
    printf("Entre um valor maior ou igual a zero x=");
    scanf("%f", &x);
    if (x < 0) {
        printf("O valor deve ser maior ou igual a zero!");
        return 0;
    }
    printf("f(%.3f) = %.3lf", x, (sqrt(x) + (x / 2) + pow(x, x)));
    return 0;
}
