#include <stdio.h>

int main() {
    int inteiro;
    printf("Encontraremos a representação binária para o número inteiro dado. Entre com o inteiro: ");
    scanf("%d", &inteiro);

    // Para transformarmos o número inteiro em binário, temos que repetidamente
    // fazer a divisão inteira do 'inteiro' por 2 até resultar zero (terminamos
    // o número) enquanto guardamos os restos da divisão. Da esquerda para a di-
    // reita, os restos representam os valores binários

    int binario[32];
    int indice = 0;

    // Representamos o sinal
    if(inteiro < 0) {
        binario[indice] = 1;
        inteiro = -inteiro;
    } else {
        binario[indice] = 0;
    }

    do {
        // Guardamos o resto da divisão por 2 de inteiro
        int resto = inteiro % 2;
        // Dividimos inteiro por 2
        inteiro = inteiro / 2;

        binario[++indice] = resto;
        printf("inteiro = %d, resto = %d\n", inteiro, resto);
        printf("binario[%d] = %d\n", indice, binario[indice]);
        if(indice > 32)
            printf("overflow\n");
    } while(inteiro != 0);

    // O resto é calculado "de ponta cabeça", logo, precisamos inverter o número
    // (o último resto é o primeiro dígito representativo no binário)
    if(indice != 32 - 1) {
        for(int i = 32 - 1; i > 0; i--) {
            if((1 + ((32 - 1) - i)) <= indice)
                // Moveremos o índice 1 para o índice 31 (...) até indice
                binario[i] = binario[1 + ((32 - 1) - i)];
            else
                binario[i] = 0;
        }
    }

    printf("O número binário é ");
    for(int i = 0; i < 32; i++)
        printf("%d", binario[i]);
    printf(".\n");
}
