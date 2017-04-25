#include <stdio.h>

/*
 * Author: Rafael Sartori (RA: 186154)
 *
 * O programa receberá de entrada os respectivos valores:
 * - a altura da bomba no momento do lançamento
 * - a velocidade vertical da bomba no momento do lançamento
 * - distância da base de comunicação até a base do Império
 * - força do propulsor (em Newtons) instalada na bomba
 * O programa detornará, então, o tempo de espera para a ativação do propulsor
 * instalado na bomba.
 */
int main(void) {
    float altura, velocidadeBomba, distanciaImperio, forcaPropulsor;

    // Recebendo os valores de entrada respectivamente
    scanf("%f", &altura);
    scanf("%f", &velocidadeBomba);
    scanf("%f", &distanciaImperio);
    scanf("%f", &forcaPropulsor);

    /* Imprimindo tempo necessário de espera até ativação do propulsor a partir
     * do lançamento, dado pela diferença: tempo disponível - tempo necessário
     * - Tempo disponível pode ser calculado pela divisão da altura pela velocidade
     *   vertical da bomba
     * - Tempo necessário pode ser calculado pela divisão da distância pela força do
     *   propulsor (que será, em valor absoluto, igual à velocidade horizontal da bomba
     *   após ativação do propulsor)
     */
     printf("%.3f\n", ((altura / velocidadeBomba) - (distanciaImperio / forcaPropulsor)));

     return 0;
}
