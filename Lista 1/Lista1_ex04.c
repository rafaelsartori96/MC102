//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int main(void) {
    int x, y;
    printf("Entre um valor inteiro para x=");
    scanf("%d", &y);
    printf("Entre um valor inteiro para y=");
    scanf("%d", &x);
    /*// Trocando valores: salvo x em a, troco x por y e troco y por a (x)
    int a;
    a = x;
    x = y;
    y = a;
    // Agora, para trocar os valores x e y de variável sem usar uma terceira, basta usar o scanf em y e depois x. */

    printf("Trocando valores...\nO valor de x agora é %d, e o de y, %d.\n", x, y);
    return 0;
}
