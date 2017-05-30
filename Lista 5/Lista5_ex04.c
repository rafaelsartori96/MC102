#include <stdio.h>
#include <stdlib.h>


int pot(int b, int k) {
    if(k == 1) return b;
    return b * pot(b, k - 1);
}

int menorBaseLog(int n) {
    for(int base = 2; ; base++) {
        // Retorne -1 caso não encontramos uma base inteira
        if(base > n) return -1;

        for(int k = 1; ; k++) {
            int potencia = pot(base, k);

            if(potencia == n) {
                return base;
            } else if(potencia > n) {
                // Procuramos numa base maior
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Entre com o número: ");
    scanf("%d", &n);

    printf(
        "A menor base que resulta em n quando elevado a um número inteiro é %d\n",
        menorBaseLog(n)
    );
}
