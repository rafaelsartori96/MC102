//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>

int listSize = 3;

int main(void) {
    float input[listSize], ordered[listSize];

    printf("Você deve entrar %d valores.\n", listSize);
    for (int i = 0; i < listSize; ++i) {
        printf("Entre o %dº valor: ", i + 1);
        // Colocando os valores de input em cada variável da array, para o número de elementos na lista.
        scanf("%f", &input[i]);
    }

    printf("Imprimindo a lista não ordenada:\n");
    for (int i = 0; i < listSize; ++i)
        printf("input[%d]=%.2f\n", i, input[i]);

    /*
     * Já que eu não consegui conferir "if (!input[i]) {" caso o índice i de input não tivesse sido definido, vou colo-
     * car o valor mínimo em todos os elementos de ordered
     */
    float minimum = input[0];
    for (int i = 0; i < listSize; ++i)
        if (input[i] < minimum) minimum = input[i];
    for (int i = 0; i < listSize; ++i)
        ordered[i] = minimum;

    // Circulando entre os elementos do input
    for (int i = 0; i < listSize; ++i) {
        // Vamos conferir todos os elementos de ordered
        for (int j = 0; j < listSize; ++j) {
            // Caso o elemento do input for maior que o do ordered
            if (input[i] > ordered[j]) {
                // Passar os elementos (de ordered) de frente pra trás começando pelo final
                // Dessa forma, não perdemos valores e conseguimos manter a ordem passada
                for (int k = listSize - 1; k > j; --k)
                    ordered[k] = ordered[k - 1];
                // Finalmente, mudamos o ordered para o input que é maior.
                ordered[j] = input[i];
            } else {
                // Se não for maior, continue buscando por ordered até ser
                continue;
            }
            break;
        }
        // Caso não substituiu nenhum valor de ordered, o elemento é o elemento mínimo, que já terá ficado naturalmente
        // no último lugar da lista.
    }

    printf("Imprimindo a lista ordenada:\n");
    for (int i = 0; i < listSize; ++i)
        printf("ordered[%d]=%.2f\n", i, ordered[i]);

    return 0;
}