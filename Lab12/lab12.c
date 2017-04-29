#include <stdio.h>
#include <string.h>

/**
 * Essa função encontrará o último índice da palavra (strlen não funciona neste
 * caso... por algum motivo estranho)
 */
int getLastWordIndex(char word[50]);

/**
 * Essa função procurará o índice da primeira palavra word que encontrar em text,
 * apenas encontrará palavras inteiras, não parciais (no meio, final, começo de
 * outras palavras)
 *
 * Nota: a função, assim como todo o projeto, ignora pontuação
 */
int searchWord(char text[1000], char word[50]);

/**
 * Essa função procurará os índices da palavra word no texto text e as removerão.
 */
void deleteWords(char text[1000], char word[50]);

/**
 * Essa função procurará os índices da palavra word no texto text e as inverterão.
 */
void invertWords(char text[1000], char word[50]);

/**
 * Essa função procurará os índices da palavra wordToReplace no texto text e as
 * substuirão com wordReplacement.
 */
void replaceWords(char text[1000], char wordToReplace[50], char wordReplacement[50]);

// Rafael Sartori Martins dos Santos (RA: 186154)
int main() {
    char text[1000];
    for(int i = 0; i < 50; i++) {
        text[i] = '#';
    }
    text[50] = '\0';
    fgets(text, 1000, stdin);
    printf("%s", text);

    int terminamos = 0;
    char comando;
    do {
        scanf("%c", &comando);

        char wordToReplace[50], wordReplacement[50], word[50];
        switch (comando) {
            case 'Q':
                terminamos = 1;
                break;
            case 'R':
                // Lendo a palavra que devemos substituir
                scanf("%s", wordToReplace);
                // Lendo a palavra com que devemos substituir
                scanf("%s", wordReplacement);

                // Realizar substituição
                replaceWords(text, wordToReplace, wordReplacement);
                printf("%s", text);
                break;
            case 'D':
                // Ler a palavra a ser manipulada
                scanf("%s", word);

                // Remove-la do texto
                deleteWords(text, word);
                printf("%s", text);
                break;
            case 'I':
                // Ler a palavra a ser manipulada
                scanf("%s", word);

                // Inverte-la no texto
                invertWords(text, word);
                printf("%s", text);
                break;
            default:
                break;
        }
    } while(!terminamos);
}

int getLastWordIndex(char word[50]) {
    for(int lastWordIndex = 0; lastWordIndex < 50; lastWordIndex++)
        if (word[lastWordIndex] == '\0' || word[lastWordIndex] == '\n')
            return lastWordIndex; // ele retorna o índice do caractere terminal
                                  // (ou seja, é o tamanho da palavra de fato)
    return 49;
}

int getLastTextIndex(char text[1000]) {
    for(int lastTextIndex = 0; lastTextIndex < 1000; lastTextIndex++)
        if (text[lastTextIndex] == '\0' || text[lastTextIndex] == '\n')
            return lastTextIndex; // ele retorna o índice do caractere terminal
                                  // (ou seja, é o tamanho da palavra de fato)
    return 999;
}

int searchWord(char text[1000], char word[50]) {
    int lastWordIndex = getLastWordIndex(word);

    int index = 0, waitingWord = 0, wordEnded = 0;
    int wordSearchIndex = 0, wordIndex = -1;

    do {
        // Se chegamos no possível início de uma palavra, vamos marcar a flag
        if(index == 0 || text[index] == ' ') {
            waitingWord = 1;
            if(text[index] == ' ') {
                index++;
                continue;
            }
        }

        // Se estamos procurando uma palavra, vamos buscá-la
        if(waitingWord) {
            if(tolower(text[index]) == tolower(word[wordSearchIndex])) {
                // Se chegamos na primeira letra da palavra, marcamos o ponto
                if(wordIndex < 0)
                    wordIndex = index;

                // Esse valor determinará se chegamos ao final da palavra buscada
                // Note que começa do zero, logo no índice zero da palavra que
                // estamos testando, ele valerá 1. Isso acontece pois o
                // wordSearchIndex é o índice do \n, \0 ou espaço da palavra
                // buscada
                wordSearchIndex++;

                // Se a palavra foi igual até o fim, vamos ver se ela termina
                // aqui
                if(wordSearchIndex == lastWordIndex) {
                    // Se ela terminar aqui, retornamos o índice inicial
                    if (text[index + 1] == ' ' || text[index + 1] == '\0' ||
                            text[index + 1] == '\n') {
                        return wordIndex;
                    } else {
                        // Se não terminar, vamos resetar a busca (e pular o res-
                        // to da palavra)
                        waitingWord = 0;
                        wordIndex = -1;
                        wordSearchIndex = 0;
                    }
                }
            } else {
                // Já que a palavra não é igual, vamos pulá-la, excluir o ponto
                // e o progresso da busca.
                waitingWord = 0;
                wordIndex = -1;
                wordSearchIndex = 0;
            }
        }

        // Se o texto acabou, terminamos tristes :(
        // Nota: poderia usar o "return -1" aqui, mas o compilador não aceitaria
        if(text[index] == '\0')
            wordEnded = 1;

        // Ou estamos conferindo a palavra, ou pulando ela até o próximo espaço:
        // de qualquer forma, precisamos continuar buscando
        index++;
    } while (!wordEnded);

    return -1;
}

void deleteWords(char text[1000], char word[50]) {
    int lastWordIndex = getLastWordIndex(word);
    int index;
    // Enquanto houver palavras encontradas
    while ((index = searchWord(text, word)) >= 0) {
        // Teremos o índice do início da palavra, o último índice de word (que é
        // o índice do '\0' terminal em word). Devemos passar todas as letras
        // sucessoras de word em text para o índice em que encontramos a palavra.
        for(int i = index + lastWordIndex, j = index - 1; ; i++, j++) {
            // Colocamos a primeira letra de text após a palavra no lugar do es-
            // paço que antecede a palavra
            text[j] = text[i];

            // Paramos se chegamos ao final
            if(text[i] == '\0')
                break;
        }
    }
}

void invertWords(char text[1000], char word[50]) {
    int lastWordIndex = getLastWordIndex(word);
    int index;
    // Enquanto houver palavras encontradas
    while ((index = searchWord(text, word)) >= 0) {
        // Teremos o índice do início da palavra, o último índice de word (que é
        // o índice do '\0' terminal em word). Devemos passar todas as letras do
        // final da palavra para o começo.
        // Nota: só devemos fazer isso até a metade, ou a palavra será 'desinver-
        // tida.
        for(int i = 0; (index + (lastWordIndex - 1) - i) > (index + i); i++) {
            // Guardamos a letra original do inicio
            char auxiliar = text[index + i];
            // Substituimos pela do fim
            text[index + i] = text[index + (lastWordIndex - 1) - i];
            // Colocamos no fim a do começo
            text[index + (lastWordIndex - 1) - i] = auxiliar;
        }
    }
}

void replaceWords(char text[1000], char wordToReplace[50], char wordReplacement[50]) {
    int index;
    // Enquanto houver palavras encontradas
    while ((index = searchWord(text, wordToReplace)) >= 0) {
        // Isso deve ser declarado após as mudanças na palavra.
        int lastTextIndex = getLastTextIndex(text) + 1;
        int lastWordToReplaceIndex = getLastWordIndex(wordToReplace);
        int lastWordReplacementIndex = getLastWordIndex(wordReplacement);
        /*printf("lastTextIndex = %d\n", lastTextIndex);
        printf("lastWordToReplaceIndex = %d\n", lastWordToReplaceIndex);
        printf("lastWordReplacementIndex = %d\n", lastWordReplacementIndex);*/

        // Devemos fazer o 'shift' das palavras (mais eficiente: não trocar se o
        // tamanho das palavras forem iguais).
        if(lastWordReplacementIndex > lastWordToReplaceIndex) {
            // Vamos começar a trocar do final, assim não perdemos letras. O novo
            // último caractere será dado pela relação
            // lastTextIndex + (lastWordReplacementIndex - lastWordToReplaceIndex).
            // Dessa forma, devemos parar quando o índice da troca chegar no final
            // da palavra que devemos trocar (excludente, não trocamos o final da
            // palavra que devemos trocar)
            /*printf("index + lastWordToReplaceIndex (limite inferior) = %d\n", index + lastWordToReplaceIndex);
            printf("index + lastWordReplacementIndex = %d\n", index + lastWordReplacementIndex);
            printf("index + (lastWordReplacementIndex - lastWordToReplaceIndex) (limite superior) = %d\n", index + (lastWordReplacementIndex - lastWordToReplaceIndex));*/
            for(int i = 0; (lastTextIndex + (lastWordReplacementIndex - lastWordToReplaceIndex) - i) >= (index + lastWordToReplaceIndex); i++) {
                // Fazemos a troca de text[novo] = text[antigo]
                text[lastTextIndex + (lastWordReplacementIndex - lastWordToReplaceIndex) - i] = text[lastTextIndex - i];
            }
        } else if(lastWordReplacementIndex < lastWordToReplaceIndex) {
            // Como a palavra é agora menor, devemos começar do começo para não
            // perdermos caracteres
            for(int i = 0; ; i++) {
                // Fazemos a troca de text[novo] = text[antigo]
                text[index + lastWordReplacementIndex + i] = text[index + lastWordToReplaceIndex + i];
                // Como não temos limite em i, temos que conferir se o caractere
                // é terminal.
                if(text[index + lastWordToReplaceIndex + i] == '\0')
                    break;
            }
        }

        // Agora podemos trocar as palavras, parando antes do novo início do tex-
        // to original (principalmente porque
        // wordReplacement[lastWordReplacementIndex] é '\0').
        for(int i = 0; i < lastWordReplacementIndex; i++) {
            text[index + i] = wordReplacement[i];
        }
    }
}
