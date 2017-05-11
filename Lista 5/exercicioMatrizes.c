#include <stdio.h>

#define TAMANHO_MAX 100

void lerMatriz(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int* linhas, int* colunas
);
void imprimirMatriz(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas
);
int soma(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
);
int diferenca(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
);
int produto(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
);
int transposta(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
);
void imprimirOcorrencias(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas
);

int main() {
    printf("Este programa irá fazer a soma, a diferença, a transposta e a múltiplicação de matrizes.\n");
    double matriz1[TAMANHO_MAX][TAMANHO_MAX];
    int linhas1, colunas1;
    double matriz2[TAMANHO_MAX][TAMANHO_MAX];
    int linhas2, colunas2;
    double matriz3[TAMANHO_MAX][TAMANHO_MAX];
    int linhas3, colunas3;

    lerMatriz(matriz1, &linhas1, &colunas1);
    printf("Matriz 1:\n");
    imprimirMatriz(matriz1, linhas1, colunas1);

    lerMatriz(matriz2, &linhas2, &colunas2);
    printf("Matriz 2:\n");
    imprimirMatriz(matriz2, linhas2, colunas2);

    printf("\n");
    if(soma(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2, matriz3, &linhas3, &colunas3)) {
        printf("Matriz soma:\n");
        imprimirMatriz(matriz3, linhas3, colunas3);
    } else {
        printf("A soma não existe!\n");
    }

    printf("\n");
    if(diferenca(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2, matriz3, &linhas3, &colunas3)) {
        printf("Matriz diferença:\n");
        imprimirMatriz(matriz3, linhas3, colunas3);
    } else {
        printf("A diferença não existe!\n");
    }

    printf("\n");
    if(produto(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2, matriz3, &linhas3, &colunas3)) {
        printf("Matriz produto:\n");
        imprimirMatriz(matriz3, linhas3, colunas3);
    } else {
        printf("O produto não existe!\n");
    }

    printf("\n");
    if(transposta(matriz1, linhas1, colunas1, matriz3, &linhas3, &colunas3)) {
        printf("Matriz transposta de 1:\n");
        imprimirMatriz(matriz3, linhas3, colunas3);
    } else {
        printf("A transposta da primeira matriz não existe!\n");
    }

    printf("\n");
    if(transposta(matriz2, linhas2, colunas2, matriz3, &linhas3, &colunas3)) {
        printf("Matriz transposta de 2:\n");
        imprimirMatriz(matriz3, linhas3, colunas3);
    } else {
        printf("A transposta da segunda matriz não existe!\n");
    }

    printf("\n");
    // Agora, vamos determinar a moda e o número de menor ocorrências nas matrizes
    printf("Matriz 1:\n");
    imprimirOcorrencias(matriz1, linhas1, colunas1);
    printf("\nMatriz 2:\n");
    imprimirOcorrencias(matriz2, linhas2, colunas2);
}

void lerMatriz(double matriz[TAMANHO_MAX][TAMANHO_MAX], int* linhas, int* colunas) {
    printf("Entre com o número de linhas l e colunas c (l, c <= %d): ", TAMANHO_MAX);
    scanf("%d %d", linhas, colunas);

    printf("Entre com os elementos das matrizes: ");
    for(int linha = 0; linha < *linhas; linha++) {
        for(int coluna = 0; coluna < *colunas; coluna++) {
            scanf("%lf", &matriz[linha][coluna]);
        }
    }
}

void imprimirMatriz(double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas) {
    for(int linha = 0; linha < linhas; linha++) {
        for(int coluna = 0; coluna < colunas; coluna++) {
            if(coluna > 0)
                printf(" ");
            printf("%.2lf", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

int soma(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
) {
    // Checando se a soma é possível
    if(linhas1 != linhas2 || colunas1 != colunas2)
        return 0;

    for(int linha = 0; linha < linhas1; linha++) {
        for(int coluna = 0; coluna < colunas1; coluna++) {
            matriz3[linha][coluna] = matriz1[linha][coluna] + matriz2[linha][coluna];
        }
    }

    *linhas3 = linhas1;
    *colunas3 = colunas1;
    return 1;
}

int diferenca(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
) {
    // Checando se a diferença é possível
    if(linhas1 != linhas2 || colunas1 != colunas2)
        return 0;

    for(int linha = 0; linha < linhas1; linha++) {
        for(int coluna = 0; coluna < colunas1; coluna++) {
            matriz3[linha][coluna] = matriz1[linha][coluna] - matriz2[linha][coluna];
        }
    }

    *linhas3 = linhas1;
    *colunas3 = colunas1;
    return 1;
}

int produto(
    double matriz1[TAMANHO_MAX][TAMANHO_MAX], int linhas1, int colunas1,
    double matriz2[TAMANHO_MAX][TAMANHO_MAX], int linhas2, int colunas2,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
) {
    // Checando se o produto é possível
    if(colunas1 != linhas2)
        return 0;

    // A ideia era fazer o produto do modo mais eficiente (usando acesso sequên-
    // cial), porém isso só funciona para matrizes quadradas (usando a transpos-
    // ta
    // double matriz2_t[TAMANHO_MAX][TAMANHO_MAX];
    // int linhas2_t, colunas2_t;
    // transposta(matriz2, linhas2, colunas2, matriz2_t, &linhas2_t, &colunas2_t);

    // linha de A x coluna de B
    // M(i, j) = somatorio(A(i, k) + B(k, j)); k de 1 a coluna1/linha2
    for(int linha = 0; linha < linhas1; linha++) {
        for(int coluna = 0; coluna < colunas2; coluna++) {
            // Lembrar de que não inicializamos a matriz3!
            matriz3[linha][coluna] = 0;
            for(int k = 0; k < linhas2; k++) {
                matriz3[linha][coluna] += (matriz1[linha][k] * matriz2[k][coluna]);
            }
        }
    }

    *linhas3 = linhas1;
    *colunas3 = colunas2;
    return 1;
}

int transposta(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas,
    double matriz3[TAMANHO_MAX][TAMANHO_MAX], int* linhas3, int* colunas3
) {
    if(linhas != colunas)
        return 0;

    // M(i, j) = M(j, i)
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matriz3[j][i] = matriz[i][j];
        }
    }
    return 1;
}

int buscarValor(double vetor[TAMANHO_MAX * TAMANHO_MAX], int tamanho, double valor) {
    for(int i = 0; i < tamanho; i++) {
        if(valor == vetor[i])
            return i;
    }
    // Se chegamos aqui, não encontramos
    return -1;
}

void imprimirOcorrencias(
    double matriz[TAMANHO_MAX][TAMANHO_MAX], int linhas, int colunas
) {
    int tamanho = 0, indice;
    double numeros[TAMANHO_MAX * TAMANHO_MAX];
    int ocorrencias[TAMANHO_MAX * TAMANHO_MAX];

    int indiceOcorrenciaMinima = -1, indiceOcorrenciaMaxima = -1;

    for(int linha = 0; linha < linhas; linha++) {
        for(int coluna = 0; coluna < colunas; coluna++) {
            double valor = matriz[linha][coluna];

            indice = buscarValor(numeros, tamanho, valor);
            if(indice < 0) {
                indice = tamanho++;
                // Inserior valor
                numeros[indice] = valor;
                ocorrencias[indice] = 0;
            }

            // Aumentar ocorrencias
            ocorrencias[indice]++;

            // Guardando limites
            if(indiceOcorrenciaMaxima < 0 || ocorrencias[indice] >= ocorrencias[indiceOcorrenciaMaxima])
                indiceOcorrenciaMaxima = indice;
            if(indiceOcorrenciaMinima < 0 || ocorrencias[indice] <= ocorrencias[indiceOcorrenciaMinima])
                indiceOcorrenciaMinima = indice;
        }
    }

    printf("O valor de maior ocorrência (%d) foi %.2lf\nO de menor ocorrência (%d), %.2lf.\n", ocorrencias[indiceOcorrenciaMaxima], numeros[indiceOcorrenciaMaxima], ocorrencias[indiceOcorrenciaMinima], numeros[indiceOcorrenciaMinima]);
}
