#include <stdio.h>

/*
 * Author: Rafael Sartori (RA: 186154)
 *
 * O programa recebe a entrada pelo console das seguintes informações, respectivamente:
 *  - valor inicial/custo de serviço do StarUber
 *  - posição horizontal inicial daquele que requisita o serviço StarUber
 *  - posição vertical inicial daquele que requisita o serviço StarUber
 *  - posição horizontal final daquele que requisita o serviço StarUber
 *  - posição vertical final daquele que requisita o serviço StarUber
 *  - taxa por "quarteirões" a ser paga
 * Após receber dadas informações, o programa calcula o valor total da viagem, somando o valor
 * inicial com a taxa proporcional a distância de Manhatan (número de quarteirões percorridos).
 */
int main(void) {
    int valorInicial, x_inicial, y_inicial, x_final, y_final, taxa;

    // Recebendo o valor de custo inicial na variável adequada
    scanf("%d", &valorInicial);
    // Recebendo as coordenadas iniciais nas variáveis adequadas (x_inicial e y_inicial, respectivamente)
    scanf("%d", &x_inicial);
    scanf("%d", &y_inicial);
    // Recebendo as coordenadas finais nas variáveis adequadas (x_final e y_final, respectivamente)
    scanf("%d", &x_final);
    scanf("%d", &y_final);
    // Finalmente, recebendo o valor cobrado proporcional à distância de Manhatan na variável taxa.
    scanf("%d", &taxa);

    // Calculando e imprimindo o valor final, dado pela fórmula: valorInicial + ((x_final - x_inicial)+(y_final - y_inicial))*taxa
    printf("%d\n", valorInicial + ((x_final - x_inicial) + (y_final - y_inicial))*taxa);

    return 0;
}
