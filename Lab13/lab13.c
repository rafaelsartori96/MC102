#include <stdio.h>

// Rafael Sartori Martins dos Santos (RA: 186154)

/* Funcao: pertence
 *
 * Parametros:
 *   conj: vetor contendo o conjunto de entrada
 *    tam: tamanho do conjunto
 *  letra: elemento a ser verificado pertinencia
 *
 * Retorno:
 *   1 se letra pertence a conj e 0 caso contrario
 */
int pertence(char conj[], int tam, char letra){
    for(int i = 0; i < tam; i++)
        if(conj[i] == letra)
            // Encontramos a palavra, retornamos 'true'
            return 1;
    return 0;
}

/* Funcao: contido
 *
 * Parametros:
 *   conj1: vetor contendo um conjunto de entrada
 *   conj2: vetor contendo um conjunto de entrada
 *    tam1: tamanho do conjunto conj1
 *    tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   1 se conj1 esta contido em conj2 e 0 caso contrario
 */
int contido(char conj1[], char conj2[], int tam1, int tam2){
    // Como estar contido significa que todos os elementos de conj1 estão em
    // conj2, se acharmos um elemento que prova o contrário, retornamos 'false'
    for(int i = 0; i < tam1; i++) {
        int encontramos = 0;
        for(int j = 0; j < tam2; j++) {
            // Se encontramos o elemento em conj2, retornamos
            if(conj2[j] == conj1[i]) {
                encontramos = 1;
                break;
            }
        }

        // Caso não tenhamos encontrado, retornamos 'false', pois não está con-
        // tido, já que possui elemento que não pertence a conj2
        if(!encontramos)
            return 0;
    }
    return 1;
}

/* Funcoes: adicao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto que terá incluído o elemento
 *    tam: tamanho do conjunto
 *  letra: elemento a ser adicionado
 *
 * Retorno:
 *   tamanho do conjunto apos a operacao.
 */
int adicao(char conj[], int tam, char letra) {
    if(!pertence(conj, tam, letra)) {
        // Aparentemente devemos manter a ordem crescente, então vamos colocar a
        // letra após uma letra que seja menor que ela (usando tabela ASCII)
        /*for(int i = tam - 1; i >= 0; i--) {
            // Quando a letra tiver valor decimal maior que a letra em i, acha-
            // mos a posição que a letra dada deveria estar (pois o 'a' é o de
            // menor valor, e o 'z', o de maior)
            if(letra > conj[i]) {
                for(int j = tam; j > i; j++) {
                    // Passamos a letra anterior à próxima, até chegarmos em i + 1
                    conj[j] = conj[j - 1];
                }
                // Finalmente, adicionamos 'letra'
                conj[i] = letra;
                return tam + 1;
            }
        }
        // Algo errado não está certo: não deve chegar aqui
        printf("Erro!\n");
        return -1;*/
        conj[tam] = letra;
        return tam + 1;
    } else {
        return tam;
    }
}

/* Funcoes: subtracao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto que terá removido o elemento
 *    tam: tamanho do conjunto
 *  letra: elemento a ser removido
 *
 * Retorno:
 *   tamanho do conjunto apos a operacao.
 */
int subtracao(char conj[], int tam, char letra){
    if(pertence(conj, tam, letra)) {
        for(int i = 0; i < tam; i++) {
            // Encontramos o elemento que deve ser removido.
            if(conj[i] == letra) {
                for(int j = i; j < tam - 1; j++) {
                    // Passamos o elemento sucessor para o atual
                    conj[j] = conj[j + 1];
                }
                // Já que encontramos e removemos, podemos retornar
                return tam - 1;
            }
        }
        // Algo errado não está certo: não deve chegar aqui
        printf("Erro!\n");
        return -1;
    } else {
        return tam;
    }
}

/* Funcoes: uniao, intersecao e diferenca
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *     conj1: vetor contendo o conjunto de entrada do primeiro operando
 *     conj2: vetor contendo o conjunto de entrada do segundo operando
 *      tam1: tamanho do conjunto conj1
 *      tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int uniao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int tam = 0;
    // Soma padrão: adicionamos todas as letras de ambos os conjuntos
    for(int i = 0; i < tam1; i++) {
        tam = adicao(destRes, tam, conj1[i]);
    }
    for(int i = 0; i < tam2; i++) {
        tam = adicao(destRes, tam, conj2[i]);
    }
    return tam;
}

int intersecao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int tam = 0;
    for(int i = 0; i < tam1; i++) {
        // Se pertence aos dois, incluir
        if(pertence(conj2, tam2, conj1[i])) {
            tam = adicao(destRes, tam, conj1[i]);
        }
    }
    return tam;
}

int diferenca(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int tam = 0;
    for(int i = 0; i < tam1; i++) {
        // Se pertence a um mas não pertence ao outro, incluir
        if(!pertence(conj2, tam2, conj1[i])) {
            tam = adicao(destRes, tam, conj1[i]);
        }
    }
    /*
     * Diferença: elementos que estão em conj1, mas NÃO estão em conj2
    // Repetir para o outro conjunto
    for(int i = 0; i < tam2; i++) {
        if(!pertence(conj1, tam1, conj2[i])) {
            tam = adicao(destRes, tam, conj2[i]);
        }
    }*/
    return tam;
}


/* Funcao: complemento
 * Guarda em conjRes o resultado da operação U-conj, onde U é o conjunto
 * de todas as letras minusculas do alfabeto ingles
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *      conj: vetor contendo o conjunto de entrada do primeiro operando
 *       tam: tamanho do conjunto conj
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int complemento(char conjRes[], char conj2[], int tam2){
    char conj1[30]; // Tamanho padrão usado no lab13_main, mas poderia ser sim-
    // plesmente o número de letras no alfabeto inglês
    int tam1 = 0;
    // Alfabeto minúsculo inglês em decimais: 97 -> 122
    for(int i = 97; i <= 122; i++) {
        conj1[tam1++] = (char) i;
        // Nota: tam1 sempre será acrescido de um, ou seja, na última iteração,
        // teremos o tamanho real do vetor.
    }

    // Agora que temos o conjunto que contém todo o alfabeto, faremos a diferença:
    return diferenca(conjRes, conj1, conj2, tam1, tam2);
}
