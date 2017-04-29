#include <stdio.h>

// m >= n
int mdc(int m, int n) {
    int mdc = 1;
    // Para acharmos o maior divisor comum, devemos ver qual resto da divisão
    // inteira resulta zero para os dois valores.
    for(int i = 2; i < n; i++) {
        if((m % i) == 0 && (n % i) == 0)
            // Encontramos um divisor comum maior do que o anterior
            mdc = i;
    }

    return mdc;
}

int main() {
    int m, n;
    printf("Encontraremos o mdc(m, n), m >= n. Entre com m: ");
    scanf("%d", &m);
    printf("Entre com n: ");
    scanf("%d", &n);

    printf("O maior divisor comum entre %d e %d é %d\n", m, n, mdc(m, n));
}
