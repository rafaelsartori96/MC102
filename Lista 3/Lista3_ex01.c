#include <stdio.h>

int main() {
    int numeros;
    printf("Calcularemos a média de n números reais. Entre um natural n: ");
    scanf("%d", &numeros);

    double soma = 0, valor;
    printf("Entre com os valores: ");
    for(int i = 0; i < numeros; i++) {
        scanf("%lf", &valor);
        soma += valor;
    }

    printf("A média calculada é %.2lf.\n", (soma / numeros));
}
