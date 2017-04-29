#include <stdio.h>
#include <math.h>

double square(double value) {
    return value * value;
}

int main() {
    int numeros;
    printf("Calcularemos a média de n números reais. Entre um natural n: ");
    scanf("%d", &numeros);

    double soma = 0, valores[numeros], media;
    printf("Entre com os valores: ");
    for(int i = 0; i < numeros; i++) {
        scanf("%lf", &valores[i]);
        soma += valores[i];
    }

    media = (soma / numeros);
    printf("A média calculada é %.2lf.\n", media);

    double desvioPadrao;
    soma = 0;
    for(int i = 0; i < numeros; i++) {
        soma += square(valores[i] - media);
    }

    desvioPadrao = sqrt((soma  / (numeros - 1)));
    printf("O desvio padrão calculado é %lf.\n", desvioPadrao);
}
