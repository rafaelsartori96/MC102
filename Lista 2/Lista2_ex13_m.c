#include <stdio.h>

int potencia10(int potencia) {
    if(potencia == 0) return 1;
    return 10 * potencia10(potencia - 1);
}

int main() {
    int natural;
    printf("Encontraremos a representação binária para o número natural dado. Entre com o natural: ");
    scanf("%d", &natural);

    // Checando os limites
    // O binário de num deve estar contido em 9 algarismos. Ou seja, é no máximo
    // 2^10 - 1
    if(natural > 1024 - 1) {
        printf("overflow\n");
        return 0;
    }

    // Para transformarmos o número natural em binário, temos que repetidamente
    // fazer a divisão inteira do 'natural' por 2 até resultar zero (terminamos
    // o número) enquanto guardamos os restos da divisão. Da esquerda para a di-
    // reita, os restos representam os valores binários

    int binario = 0, potencia = 0;

    do {
        // Guardamos o resto da divisão por 2 de natural
        int resto = natural % 2;
        // Dividimos natural por 2
        natural = natural / 2;

        binario += resto * potencia10(potencia++);
    } while(natural != 0);

    printf("O número binário é %d.\n", binario);
}
