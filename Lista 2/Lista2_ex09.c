#include <stdio.h>

float calcularLimiteInferior(int k) {
    if(k > 0)
        return (1.0f + (k * 25.0f));
    else
        return 0.0f;
}

int main() {
    int contadoresIntervalos[] = {0, 0, 0, 0};
    printf("Contaremos a quais intervalos eles pertencem. Entre com 10 números reais: ");

    float entrada;
    for(int i = 0; i < 10; i++) {
        scanf("%f", &entrada);
        for(int k = 0; k < 4; k++)
            if(entrada >= calcularLimiteInferior(k) &&
                entrada <= (25.0f + (k * 25.0f)))
                contadoresIntervalos[k]++;
    }

    for(int k = 0; k < 4; k++) {
        printf("Invervalo %.1f < x <= %.1f: %d\n", calcularLimiteInferior(k), 25.0f + (k * 25.0f), contadoresIntervalos[k]);
    }
}
