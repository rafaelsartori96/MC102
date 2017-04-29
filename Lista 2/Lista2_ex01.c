#include <stdio.h>

int main() {
    char opcoes[4][50] = {"Arroz e feijão", "Macarrão", "Churrasco", "Pizza"};

    for(int i = 0; i < 4; i++) {
        printf("%d - %s\n", i + 1, opcoes[i]);
    }

    int opcao;
    do {
        scanf("%d", &opcao);
        printf("%s\n", opcoes[opcao - 1]);
    } while(opcao < 5);
}
