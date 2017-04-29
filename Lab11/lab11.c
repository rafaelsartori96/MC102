#include <stdio.h>
#include <string.h>

// Rafael Sartori Martins dos Santos (RA: 186154)
//
// Input:
// Direção:
// mercurio = N
// venus = NE
// terra = L
// marte = SE
// jupiter = S
// saturno = SO
// urano = O
// netuno = NO
//
// Elevação do canhão:
// verde = 30
// amarelo = 45
// vermelho = 60
int main() {
    char input[1000], word[1000];
    // Recebendo o texto
    fgets(input, 1000, stdin);

    char localizacao[3];
    int angulo = -1;
    localizacao[0] = '\0';

    int esperandoAngulo = 0;
    int wordIndex = 0;

    int terminamos = 0;
    for(int i = 0; !terminamos; i++) {
        // Chegamos ao final da palavra, vamos analizá-la
        if(input[i] == ' ' || input[i] == '\n' || input[i] == '\0') {
            // Conferindo se terminamos a palavra
            if(input[i] == '\n' || input[i] == '\0')
                terminamos = 1;

            // Conferindo (e pulando) se o input contém dois espaços
            if(wordIndex == 0 && !terminamos)
                continue;

            // Terminando a string
            word[wordIndex] = '\0';

            // Vamos analisar a palavra:
            // Se ela for uma palavra que denota a localização da
            // nave espacial, devemos procurar por um angulo agora
            // Se não for, continuaremos procurando

            // Procurando angulo de ataque
            if(esperandoAngulo) {
                if(strcmp(word, "vermelho") == 0) {
                    angulo = 60;
                } else if(strcmp(word, "amarelo") == 0) {
                    angulo = 45;
                } else if(strcmp(word, "verde") == 0) {
                    angulo = 30;
                }

                // Achamos a palavra, resetaremos a palavra
                if(angulo >= 0) {
                    // Imprimindo resultado
                    printf("%s - %d\n", localizacao, angulo);

                    // Resetando palavra (o wordIndex é
                    // resetado antes do fim do if-case.
                    localizacao[0] = '\0';
                    esperandoAngulo = 0;
                    angulo = -1;
                    word[0] = '\0';
                }
                // Procurando a localização da nave
            } else {
                if(strcmp(word, "mercurio") == 0) {
                    strcpy(localizacao, "N");
                } else if(strcmp(word, "venus") == 0) {
                    strcpy(localizacao, "NE");
                } else if(strcmp(word, "terra") == 0) {
                    strcpy(localizacao, "L");
                } else if(strcmp(word, "marte") == 0) {
                    strcpy(localizacao, "SE");
                } else if(strcmp(word, "jupiter") == 0) {
                    strcpy(localizacao, "S");
                } else if(strcmp(word, "saturno") == 0) {
                    strcpy(localizacao, "SO");
                } else if(strcmp(word, "urano") == 0) {
                    strcpy(localizacao, "O");
                } else if(strcmp(word, "netuno") == 0) {
                    strcpy(localizacao, "NO");
                }
                if(localizacao[0] != '\0') {
                    esperandoAngulo = 1;
                }
            }

            // Preparando para próxima palavra
            wordIndex = 0;
            // Estamos no meio da palavra
        } else {
            word[wordIndex++] = tolower(input[i]);
        }
    }
}

