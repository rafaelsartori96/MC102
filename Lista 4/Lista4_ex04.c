#include <stdio.h>
#include <string.h>

// Retornará 0 se a palavra é inválida
int calcularQuantidadeLetras(int quantidadeLetras[26], char palavra[]) {
    for(int i = 0; i < 26; i++) {
        quantidadeLetras[i] = 0;
    }

    for(int i = 0; i < strlen(palavra); i++) {
        char caractereLowerCased = tolower(palavra[i]);

        // Não vamos aceitar palavras com caracteres especiais
        if(caractereLowerCased < 'a' || caractereLowerCased > 'z')
            return 0;

        quantidadeLetras[caractereLowerCased - 'a']++;
    }
}

int main() {
    char palavra[2][50];
    int quantidadeLetras[2][26];

    printf("Determinaremos se uma palavra é um anagrama de outra.\nNota: apenas conferiremos letras ASCII, sem acentos.\nEntre com a primeira palavra: ");
    scanf("%s", palavra[0]);
    printf("Entre com a segunda palavra: ");
    scanf("%s", palavra[1]);

    // Vamos conferir a quantidade de letras em cada palavra
    for(int i = 0; i < 2; i++)
        if(!calcularQuantidadeLetras(quantidadeLetras[i], palavra[i])) {
           printf("Erro: encontramos caractere especial!\n");
           return 0;
       }

    for(int i = 0; i < 26; i++) {
        if(quantidadeLetras[0][i] != quantidadeLetras[1][i]) {
            printf("As palavras não são anagramas: a quantidade de aparições de alguma letra na primeira palavra difere da quantidade na segunda palavra.\n");
            return 0;
        }
    }

    printf("As palavras são anagramas.\n");
}
