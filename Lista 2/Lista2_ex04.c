#include <stdio.h>

int main() {
    int numero;
    printf("Diremos se o número é primo. Digite um número natural maior do que 2: ");
    scanf("%d", &numero);

    // Vamos conferir se o número é divisível por 2, isto é, se  o resto dele
    // pela divisão por 2 é zero (divisão inteira exata).
    if(numero % 2 == 0) {
        printf("O número é divisível por %d e, portanto, não é primo.\n", 2);
        return 0;
    }

    // Já que não é par, conferimos os ímpares
    for(int i = 3; i < (numero / 2); i += 2) {
        // Analogamente, se ele for divisível por algum dos ímpares...
        if(numero % i == 0) {
            printf("O número é divisível por %d e, portanto, não é primo.\n", i);
            return 0;
        }
    }

    // Se chegamos até aqui, o número é primo
    printf("O número %d é primo.\n", numero);
}
