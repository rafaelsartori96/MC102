#include <stdio.h>
#include <stdlib.h>


void somarDivisores(int num, int *soma) {
    for(int denominador = 1; denominador < num; denominador++) {
        // Se a divisão de a / denominador tem resto zero, denominador é um
        // divisor de a
        if(num % denominador == 0) {
            (*soma) += denominador;
        }
    }
}

int amigos(int a, int b) {
    int soma = 0;
    somarDivisores(a, &soma);

    // Checamos se a soma dos divisores de a é b
    if(soma == b) {
        soma = 0;
        somarDivisores(b, &soma);
        return soma == a; // Se a soma resultar a também, a e b são amigos.
    } else {
        return 0;
    }
}

int main() {
    int a, b;
    printf("Entre com dois números: ");
    scanf("%d %d", &a, &b);

    printf(amigos(a, b) ? "a e b são números amigos.\n" : "a e b não são números amigos.\n");
}
