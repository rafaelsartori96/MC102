#include <stdio.h>

static inline double square(double x) {
    return x * x;
}

double elevadoOpti(double x, int n) {
    if(n == 1)
        return x;
    else if(n == 0)
        return 1;
    else if(n % 2 == 0)
        // x^(n) = (x^(n/2))^2; n é par
        return square(elevadoOpti(x, n / 2));
    else
        // x^(n) = x * (x^((n - 1) / 2))^2; n é impoar, então n - 1 é par
        return x * square(elevadoOpti(x, (n - 1) / 2));
}

int main() {
    double soma = 0;
    for(int i = 0; i < 100000; i++) {
        soma += elevadoOpti(0.998512, 1100);
    }
    printf("A soma total de 100000 vezes 0,998512^1100 é %.1lf.\n", soma);
}
