//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    char sexo;
    int contribuicao, idade;

    // Definindo sexo
    printf("Digite seu sexo (M para masculino, F para feminino): ");
    scanf("%c", &sexo);

    // Definindo contribuição e idade
    printf("Digite quantos anos contribuiu: ");
    scanf("%d", &contribuicao);
    printf("Finalmente, digite sua idade: ");
    scanf("%d", &idade);

    if (((sexo == 'm' || sexo == 'M') &&
         ((idade >= 65 && contribuicao >= 10) || (idade >= 63 && contribuicao >= 15))) ||
        ((sexo == 'f' || sexo == 'F') &&
         ((idade >= 63 && contribuicao >= 10) || (idade >= 61 && contribuicao >= 15))))
        printf("Aposentável\n");
    else
        printf("Não Aposentável\n");
    return 0;
}
