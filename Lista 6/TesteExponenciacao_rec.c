#include <stdio.h>

double elevado(double x, int n) {
    if(n == 1) return x;
    return x * elevado(x, n - 1);
}

int main() {
    double soma = 0;
    for(int i = 0; i < 100000; i++) {
        soma += elevado(0.998512, 1100);
    }
    printf("A soma total de 100000 vezes 0,998512^1100 é %.1lf.\n", soma);
}
