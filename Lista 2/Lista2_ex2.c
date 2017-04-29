#include <stdio.h>

int main() {
    int a, b;
    printf("Calcularemos a^b. Entre com a: ");
    scanf("%d", &a);
    printf("Entre com b: ");
    scanf("%d", &b);

    int potencia = 1;
    for(int i = 1; i <= b; i++) {
        // Multiplicar b vezes
        potencia *= a;
    }
    printf("a^b vale %d\n", potencia);
}
