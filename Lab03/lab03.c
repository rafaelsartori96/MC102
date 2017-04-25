#include <stdio.h>

/*
 * Author: Rafael Sartori Martins dos Santos(RA: 186154)
 *
 * O programa analisará se é possível reabastecer os postos A, B e C.
 * Os valores entrados são:
 * - diâmetro do tanque (metros)
 * - comprimento do tanque (metros)
 * - demanda do posto A
 * - demanda do posto B
 * - demanda do posto C
 * Baseado na quantidade (em litros!) requisitada pelo posto, o programa
 * analisa: se o caminhão carregar a quantidade suficiente, abastecerá
 * o posto.
 */
int main() {
    float diametro, comprimento, demandaA, demandaB, demandaC, volumeRemanescente;

    // Recebendo valores do console
    scanf("%f %f %f %f %f", &diametro, &comprimento, &demandaA, &demandaB, &demandaC);

    // Calculando volume remanescente no tanque (m^3 = 10^3 L)
    volumeRemanescente = 3.14f * (diametro / 2.0f) * (diametro / 2.0f) * comprimento * 1000;

    // Analisando se é possível abastecer os postos A, B e C, respectivamente
    if(volumeRemanescente >= demandaA) {
        printf("posto A foi reabastecido\n");
        volumeRemanescente -= demandaA;
    } else {
        printf("posto A nao foi reabastecido\n");
    }
    if(volumeRemanescente >= demandaB) {
        printf("posto B foi reabastecido\n");
        volumeRemanescente -= demandaB;
    } else {
        printf("posto B nao foi reabastecido\n");
    }
    if(volumeRemanescente >= demandaC) {
        printf("posto C foi reabastecido\n");
        volumeRemanescente -= demandaC;
    } else {
        printf("posto C nao foi reabastecido\n");
    }
}
