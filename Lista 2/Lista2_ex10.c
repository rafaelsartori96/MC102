#include <stdio.h>
#include <math.h>

double equacao(double x, double target) {
    return x * x - target;
}

double derivadaEquacao(double x) {
    return 2.0L * x;
}

double aproximacao(double aproximacaoAnterior, double target) {
    return aproximacaoAnterior - (equacao(aproximacaoAnterior, target) / derivadaEquacao(aproximacaoAnterior));
}

int main() {
    double target;
    printf("Encontraremos a aproximação para raiz quadrada de x. Entre com x: ");
    scanf("%lf", &target);

    double aproximacaoAnterior = target / 2.0l;
    for(int i = 0; i < 20; i++) {
        aproximacaoAnterior = aproximacao(aproximacaoAnterior, target);
    }

    printf("A aproximação encontrada de sqrt(%.2lf) é %lf.\nA calculada pela biblioteca math.h é %lf.\n", target, aproximacaoAnterior, sqrt(target));
}
