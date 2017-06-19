#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    unsigned int r, g, b;
} Pixel;

typedef struct {
    unsigned int width, height, intensidadeMaxima;
    Pixel *imagem;
} Imagem;


static inline Pixel *pegarPixel(Imagem *imagem, int x, int y) {
    if(y >= imagem->height || y < 0 || x >= imagem->width || x < 0) return NULL;
    // Usando aritmética de matrizes para ponteiros, buscamos o pixel na posição
    // x, y pela equação:
    // (y * width) + x
    return imagem->imagem + ((y * imagem->width) + x);
}

Imagem *lerImagem(FILE *arquivo) {
    // Primeiro item: tipo de imagem, leremos 'P3'
    {
        char tipo[30];
        fscanf(arquivo, "%s", tipo);

        if(strcmp(tipo, "P3") != 0) {
            printf("A imagem não é do tipo 'P3'. Tipo lido: %s\n", tipo);
            return NULL;
        }
    }

    Imagem *imagem = NULL;
    imagem = malloc(sizeof(Imagem));
    if(imagem == NULL) {
        printf("Erro ao alocar memória para imagem.\n");
        return NULL;
    }

    // Lendo width e height
    fscanf(arquivo, "%u %u", &imagem->width, &imagem->height);
    // Lendo 'Imax'
    fscanf(arquivo, "%u", &imagem->intensidadeMaxima);

    // Alocando width * height pixels
    imagem->imagem = NULL;
    imagem->imagem = malloc(imagem->width * imagem->height * sizeof(Pixel));
    if(imagem->imagem == NULL) {
        printf("Erro ao alocar memória para dados de imagem.\n");
        return NULL;
    }

    // Lendo os valores r, g e b
    for(int y = 0; y < imagem->height; y++) {
        for(int x = 0; x < imagem->width; x++) {
            Pixel *pixel = pegarPixel(imagem, x, y);
            // Lendo 3 valores, red, green e blue respectivamente, para cada x, y
            fscanf(arquivo, "%u %u %u", &pixel->r, &pixel->g, &pixel->b);
            if(pixel->r > imagem->intensidadeMaxima
                || pixel->g > imagem->intensidadeMaxima
                || pixel->b > imagem->intensidadeMaxima) {
                    printf("Valor fora dos limites da imagem no pixel %dx%d!\n", x, y);
            }
        }
    }

    // Retornamos o apontador ao terminar
    return imagem;
}

int salvarImagem(FILE *arquivo, Imagem *imagem) {
    if(imagem == NULL) {
        printf("Não é possível salvar uma imagem NULL.\n");
        return 0;
    }
    // Colocaremos o tipo de imagem: P3
    fprintf(arquivo, "%s\n", "P3");

    // Colocando width e height
    fprintf(arquivo, "%u %u\n", imagem->width, imagem->height);
    // Colocando 'Imax'
    fprintf(arquivo, "%u\n", imagem->intensidadeMaxima);

    // Colocando os pixels
    for(int y = 0; y < imagem->height; y++) {
        for(int x = 0; x < imagem->width; x++) {
            Pixel *pixel = pegarPixel(imagem, x, y);
            // Colocando um espaço para separar os pixels
            if(x > 0) fprintf(arquivo, " ");
            // Colocando 3 valores, red, green e blue respectivamente, para cada x, y
            fprintf(arquivo, "%u %u %u", pixel->r, pixel->g, pixel->b);
        }
        fprintf(arquivo, "\n");
    }

    // Retornamos o apontador ao terminar
    return 1;
}

void liberaImagem(Imagem *imagem) {
    if(imagem == NULL) return;

    // Libera todos os dados alocados dinâmicamente
    free(imagem->imagem);
    free(imagem);
}

void esticarContraste(Imagem *imagem) {
    Pixel min, max;

    // Copiando primeiro pixel para o min e para o máximo
    min = *pegarPixel(imagem, 0, 0);
    max = min;

    {
        Pixel flutuante;
        for(int y = 1; y < imagem->height; y++) {
            for(int x = 1; x < imagem->width; x++) {
                flutuante = *pegarPixel(imagem, x, y);

                // Conferindo a cor vermelha (red)
                if(flutuante.r > max.r)
                    max.r = flutuante.r;
                else if(flutuante.r < min.r)
                    min.r = flutuante.r;

                // Conferindo a cor verde (green)
                if(flutuante.g > max.g)
                    max.g = flutuante.g;
                else if(flutuante.g < min.g)
                    min.g = flutuante.g;

                // Conferindo a cor azul (blue)
                if(flutuante.b > max.b)
                    max.b = flutuante.b;
                else if(flutuante.b < min.b)
                    min.b = flutuante.b;
            }
        }
    }

    // Alterando os contrates
    {
        Pixel *flutuante;
        for(int y = 0; y < imagem->height; y++) {
            for(int x = 0; x < imagem->width; x++) {
                flutuante = pegarPixel(imagem, x, y);

                if((max.r - min.r) != 0)
                    flutuante->r = floor(((flutuante->r - min.r) * imagem->intensidadeMaxima) / (max.r - min.r));
                else
                    flutuante->r = imagem->intensidadeMaxima;

                if((max.g - min.g) != 0)
                    flutuante->g = floor(((flutuante->g - min.g) * imagem->intensidadeMaxima) / (max.g - min.g));
                else
                    flutuante->g = imagem->intensidadeMaxima;

                if((max.b - min.b) != 0)
                    flutuante->b = floor(((flutuante->b - min.b) * imagem->intensidadeMaxima) / (max.b - min.b));
                else
                    flutuante->b = imagem->intensidadeMaxima;
            }
        }
    }
}

void normalizar(Imagem *imagem) {
    Pixel *flutuante;
    // Alterando os pixels
    for(int y = 0; y < imagem->height; y++) {
        for(int x = 0; x < imagem->width; x++) {
            flutuante = pegarPixel(imagem, x, y);
            unsigned int soma = (flutuante->r + flutuante->g + flutuante->b);
            // Escala de cinza: fazer a "média" de cada cor em cada pixel
            if(soma != 0) {
                flutuante->r = floor((flutuante->r * imagem->intensidadeMaxima) / soma);
                flutuante->g = floor((flutuante->g * imagem->intensidadeMaxima) / soma);
                flutuante->b = floor((flutuante->b * imagem->intensidadeMaxima) / soma);
            } else {
                flutuante->r = 0;
                flutuante->g = 0;
                flutuante->b = 0;
            }
        }
    }
}

void escalaCinza(Imagem *imagem) {
    Pixel *flutuante;
    // Alterando os pixels
    for(int y = 0; y < imagem->height; y++) {
        for(int x = 0; x < imagem->width; x++) {
            flutuante = pegarPixel(imagem, x, y);
            // Escala de cinza: fazer a "média" de cada cor em cada pixel
            flutuante->r = floor((flutuante->r + flutuante->g + flutuante->b) / 3);
            flutuante->g = flutuante->r;
            flutuante->b = flutuante->r;
        }
    }
}

// Rafael Sartori Martins dos Santos (RA: 186154)
int main(int argc, char **argv) {
    // Conferindo o número de argumentos
    if (argc != 3) {
        fprintf(stderr, "Argumentos invalidos. Use:\n");
        fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
        fprintf(stderr, "Usado:");
        for (int i = 0; i < argc; i++) {
	        fprintf(stderr, " %s", argv[i]);
        }
        fprintf(stderr, "\n");
        return 1;
    }

    char efeito[20];

    /*
     * Argumento 0: comando utilizado
     * Argumento 1: nome do arquivo de entrada
     * Argumento 2: nome do arquivo de saída
     */
    FILE *arquivoEntrada = fopen(argv[1], "r");
    if(arquivoEntrada == NULL) {
        printf("Erro ao abrir arquivo de entrada!\n");
        return 2;
    }

    FILE *arquivoSaida = fopen(argv[2], "w");
    if(arquivoSaida == NULL) {
        printf("Erro ao abrir arquivo de saída!\n");
        return 3;
    }

    // Criando variável de imagem e fechando o arquivo de entrada
    Imagem *entrada = lerImagem(arquivoEntrada);
    if(entrada == NULL) {
        printf("Erro ao abrir imagem!\n");
        return 4;
    }
    fclose(arquivoEntrada);

    // Lendo comando de efeito, 'strcmp' retorna 0 quando são strings iguais
    scanf("%s", efeito);
    if(strcmp(efeito, "esticar") == 0) {
        esticarContraste(entrada);
    } else if(strcmp(efeito, "cinza") == 0) {
        escalaCinza(entrada);
    } else if(strcmp(efeito, "normalizar") == 0) {
        normalizar(entrada);
    } else {
        printf("Comando não reconhecido!\n");
    }

    salvarImagem(arquivoSaida, entrada);
    fclose(arquivoSaida);
    liberaImagem(entrada);
    return 0;
}
