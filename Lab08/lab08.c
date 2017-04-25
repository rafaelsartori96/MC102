#include <stdio.h>

int isTriangulo(char geometria) {
    return geometria == 't' || geometria == 'T';
}

int isQuadrado(char geometria) {
    return geometria == 'Q' || geometria == 'q';
}

int isLosango(char geometria) {
    return geometria == 'L' || geometria == 'l';
}

int getLargura(char geometria, int altura) {
    if(isTriangulo(geometria) || isQuadrado(geometria))
        return (2 * altura - 1) + 4;
    else if(isLosango(geometria))
        return altura + 4;
    else
        return -1;
}

void imprimirMoldura(int largura) {
    for(int i = 1; i <= largura; i++)
        printf(".");
    printf("\n");
}

void imprimirEspacos(int numero) {
    for(int i = 1; i <= numero; i++)
        printf(" ");
}

/*
 * Rafael Sartori Martins dos Santos (RA: 186154)
 *
 *
 *
 */
int main() {
    int altura;
    char geometria;
    scanf("%c %d", &geometria, &altura);

    if(altura < 2 || ((geometria == 'l' || geometria == 'L') && altura % 2 == 0)) {
        printf("entrada invalida\n");
        return 0;
    }

    int largura = getLargura(geometria, altura);
    if(largura < 0) {
        printf("entrada invalida\n");
        return 0;
    }

    imprimirMoldura(largura);
    largura -= 2;

    int triangulo_numEspacos = largura / 2;
    int losango_numEspacos = largura / 2;

    for(int linha = 1; linha <= altura; linha++) {
        printf(".");
        if(isTriangulo(geometria)) {
            int ultimaEstrela = -1;

            imprimirEspacos(triangulo_numEspacos);
            for(int coluna = triangulo_numEspacos + 1; coluna <= largura - triangulo_numEspacos; coluna++) {
                if(ultimaEstrela < 0 || coluna - ultimaEstrela == 2) {
                    printf("*");
                    ultimaEstrela = coluna;
                } else {
                    printf(" ");
                }
            }
            imprimirEspacos(triangulo_numEspacos);
            triangulo_numEspacos--;
        } else if(isLosango(geometria)) {
            int ultimaEstrela = -1;

            imprimirEspacos(losango_numEspacos);
            for(int coluna = losango_numEspacos + 1; coluna <= largura - losango_numEspacos; coluna++) {
                if(ultimaEstrela < 0 || coluna - ultimaEstrela == 2) {
                    printf("*");
                    ultimaEstrela = coluna;
                } else {
                    printf(" ");
                }
            }
            imprimirEspacos(losango_numEspacos);
            if(linha <= altura / 2)
                losango_numEspacos--; // Mais uma estrela será impressa, até chegar no máximo (altura / 2) + 1,
                                      //de onde ela decrescerá novamente
            else
                losango_numEspacos++;
        } else if(isQuadrado(geometria)) {
            int ultimoEspaco = 1;
            printf(" ");

            for(int coluna = 2; coluna <= largura; coluna ++) {
                if(coluna - ultimoEspaco == 2) {
                    printf(" ");
                    ultimoEspaco = coluna;
                } else {
                    printf("*");
                }
            }
        } else {
            printf("entrada invalida\n");
            return 0;
        }
        printf(".\n");
    }

    largura += 2;
    imprimirMoldura(largura);
}
