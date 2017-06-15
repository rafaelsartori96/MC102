#include <stdio.h>
#include <stdlib.h>


int primo(int n, int *primoMenor, int *primoMaior) {
    if(n <= 3) return 0;
    int definido = 0;
    int p_menor = n, p_maior = 0;

    for(int divisor = 2; divisor < n; divisor++) {
        // Se o divisor tem resto zero
        if(n % divisor == 0) {
            if(divisor < p_menor)
                p_menor = divisor;
            if(divisor > p_maior)
                p_maior = divisor;
            definido = 1;
        }
    }

    // Se encontramos valores...
    if(definido) {
        *primoMenor = p_menor;
        *primoMaior = p_maior;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, menorPrimo, maiorPrimo;
    printf("Encontraremos o menor e maior primos do número digitado: ");
    scanf("%d", &n);

    if(primo(n, &menorPrimo, &maiorPrimo)) {
        printf("O maior primo é %d, o menor, %d.\n", maiorPrimo, menorPrimo);
    } else {
        printf("Não foi possível encontrar o maior e menor primo de %d.\n", n);
    }
}
