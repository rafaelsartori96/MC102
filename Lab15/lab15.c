/* Laboratorio 15B - Brincando com cordas
 * Nome: Rafael Sartori Martins dos Santos
 * RA: 186154
 */

#include <stdio.h>
#include <string.h>

/* Funcao: removePadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo as ocorrencias de um dado padrao.
 *
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *       padrao: subsequencia de movimentos, cujas ocorrencias devem ser removidas
 *    targetStr: sequencia obtida apos a remocao de str de todas as ocorrencias do dado padrao.
 *
 *
 * Retorno:
 *
 *    1, se as occorrencias do dado padrao foram removidas
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15];
 *
 *     char padrao1[3] = "+-"
 *     char padrao2[3] = "**"
 *
 *     removePadrao(seq1, padrao1, seq2); // seq2 sera "**-*+++"
 *     removePadrao(seq1, padrao2, seq2); // seq2 sera "+-*+-*-*+++"
 *
 */
int removePadrao(char str[], char padrao[], char targetStr[]) {
    int alteramos = 0;

    // Devemos remover o padrão todas as vezes que ele aparecer
    // Laço de 0 ao índice do '\0' (inclusive)
    for(int i = 0, j = 0; i <= strlen(str); i++) {
        int contemPadrao = 1;

        // Laço de 0 até o último CARACTERE válido de 'padrao', desde que não
        // comparamos com o '\0' de 'str'
        for(int k = 0; k < strlen(padrao); k++) {
            // Conferimos o limite de 'str'
            if(i + k >= strlen(str)) {
                contemPadrao = 0;
                break;
            }

            // Se encontramos alguma letra que não faz parte do padrão
            if(str[i + k] != padrao[k]) {
                contemPadrao = 0;
                break;
            }
        }

        if(!contemPadrao) {
            // Colocamos caso não encontramos o padrão a ser removido
            targetStr[j++] = str[i];
        } else {
            i += strlen(padrao) - 1;
            alteramos = 1;
        }
    }

    return alteramos;
}

/* Funcao: removeBloco
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo o bloco inicial delimitado pelo dado caractere.
 *
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *            c: caractere delimitador do bloco a ser removido
 *    targetStr: se str comeca com o caractere do parametro c, targetStr contera a sequencia obtida
 *               apos a remocao (de str) do bloco de movimentos da primeira posicao de str ate a
 *               segunda ocorrencia (inclusive) do caractere do parametro c. Se nao exsitir uma segunda
 *               ocorrencia do caracter do parametro c, targetStr deve conter a sequencia vazia.
 *
 * Retorno:
 *
 *    1, se o bloco foi removido
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15] = "*+-*+-*-*+++";
 *     char seq3[15] = "*+-+--+++";
 *     char seq4[15];
 *
 *     removeBloco(seq1, '*', seq4); // seq4 sera "+-*+-*-*+++"
 *     removeBloco(seq2, '*', seq4); // seq4 sera "+-*-*+++"
 *     removeBloco(seq3, '*', seq4); // seq4 sera "" (sequencia vazia)
 *
 */
int removeBloco(char str[], char c, char targetStr[]) {
    // Se começamos com o caractere c
    if(str[0] == c) {
        // Definimos o último índice que devemos remover
        int ultimoIndice = strlen(str) - 1;
        // Laço em i de 1 até o último caractere de 'str', procurando 'c'
        for(int i = 1; i < strlen(str); i++) {
            if(str[i] == c) {
                ultimoIndice = i;
                break;
            }
        }

        // Agora, removemos este trecho, o primeiro índice após ultimoIndice
        // deverá estar em 0
        for(int i = 0; ; i++) {
            targetStr[i] = str[ultimoIndice + 1 + i];

            // Caso chegamos no '\0', terminamos a string
            if(str[ultimoIndice + 1 + i] == '\0')
                return 1;
        }
    }
    return 0;
}

/* Funcao: substituiPadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    substituindo as ocorrencias de um dado padrao por um novo padrao.
 *
 * Parametros:
 *           str: sequencia de movimentos '+', '-', '*'
 *        padrao: subsequencia de movimentos, cujas ocorrencias devem ser substituidas pelo novoPadrao
 *    novoPadrao: subsequencia de movimentos que deve substituir cada ocorrencia do dado padrao
 *     targetStr: sequencia obtida apos a substituicao em str de todas as ocorrencias do dado padrao
 *                pelo novoPadrao
 *
 *     Voce pode assumir que as subsequencias padrao e novoPadrao tem o mesmo tamanho.
 *
 * Retorno:
 *
 *    1, se as ocorrencias do dado padrao foram substituidas pelo novoPadrao
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+*+-+*+-*++";
 *     char seq2[15];
 *     char seq3[15];
 *
 *     char padrao[5] = "+*+"
 *     char novoPadrao[5] = "*-*"
 *
 *     substituiPadrao(seq1, padrao, novoPadrao, seq2); // seq2 sera "*-*-*-*-*++"
 *     substituiPadrao(seq2, padrao, novoPadrao, seq3);  // seq3 sera "*-*-*-*-*++"
 *
 */
int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]) {
    // Não acontece:
    // if(strlen(padrao) != strlen(novoPadrao)) {
    //     printf("DIFERENTE!!!! JASD LASD LKAKSMDNAJNSDJ ASDÇK ANSLD \n");
    //     return 0;
    // }
    int alteramos = 0;

    // Laço de 0 ao último de 'str'
    for(int i = 0; i < strlen(str); i++) {
        int contemPadrao = 1;
        // Procuramos o padrão em str[i] e caracteres posteriores
        for(int j = 0; j < strlen(padrao); j++) {
            // Conferimos o limite de 'str'
            if(i + j >= strlen(str)) {
                contemPadrao = 0;
                break;
            }

            // Conferimos se há alguma letra que não participa de str
            if(str[i + j] != padrao[j]) {
                contemPadrao = 0;
                break;
            }
        }

        // Se contém o padrão, substituimos pelo 'novoPadrao', pulando os índi-
        // ces substituídos
        if(contemPadrao) {
            // Substituimos targetStr[i] por novoPadrao[j], incrementando j
            for(int j = 0; j < strlen(novoPadrao); j++) {
                targetStr[i++] = novoPadrao[j];
            }
            // Como o for de i incrementará i, devemos decrementar em 1, pois o
            // for de j também incrementará i
            i--;
            alteramos = 1;
        } else {
            // Colocamos a letra de mesmo índice em 'targetStr'
            targetStr[i] = str[i];
        }
    }
    return alteramos;
}
