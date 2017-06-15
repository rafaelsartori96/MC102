#include <stdio.h>

int main() {
    double x = 0.998512;

    double soma = 0;
    for(int i = 0; i < 100000; i++) {
        double x_ = x;
        for(int j = 0; j <= 1100; j++) {
            // Multiplicamos de novo
            x_ *= x;
        }
        soma += x_;
    }
    printf("A soma total de 100000 vezes 0,998512^1100 é %.1lf.\n", soma);
}
