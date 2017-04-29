#include <stdio.h>

int main() {
    int n;
    printf("Calcularemos a soma de todos os naturais até n. Digite n: ");
    scanf("%d", &n);

    int soma = 0;
    for(int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("A soma é %d\n", soma);
}
