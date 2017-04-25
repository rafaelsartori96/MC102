#include <stdio.h>

/*
 * Rafael Sartori Martins dos Santos (RA: 186154)
 */
int main() {
    int first = 1, num;
    float minimum, maximum, sum = 0.0f;

    // Recebendo número de valores
    scanf("%d", &num);

    // Para todos os números recebidos
    for(int i = 0; i < num; i++) {
        float j;

        // Recebendo valor, adicionando à soma da média
        scanf("%f", &j);
        sum += j;

        // Conferindo mínimos e máximos
        if(first) {
            minimum = j;
            maximum = j;
            first = 0;
        } else {
            if(j > maximum)
                maximum = j;
            if(j < minimum)
                minimum = j;
        }
    }

    // Imprimindo respostas
    printf("%.2f\n%.2f\n%.2f\n", minimum, maximum, sum / num);
}
