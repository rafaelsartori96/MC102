#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int ra, telefone;
    char nome[100];
} Aluno;

typedef struct {
    int armazenado;
    int capacidade;
    Aluno *alunos;
} Base;


/* Funcao: criar_base
 *
 * Inicializa a base ja com a capacidade.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   n: quantidade maxima de alunos
 */
void criar_base(Base *base, int n) {
    base->capacidade = n;
    base->armazenado = 0;
    base->alunos = malloc(n * sizeof(Aluno));
    printf("Base criada.\n");
}

/* Funcao: buscar
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *
 * Retorno:
 *   Indice do registro com RA no vetor de alunos
 *   -1 caso contrario.
 */
int buscar(Base *base, int ra) {
    for(int i = 0; i < base->armazenado; i++) {
        if(base->alunos[i].ra == ra)
            return i;
    }
    return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {
    int indice;
    if((indice = buscar(base, ra)) >= 0) {
        Aluno *aluno = &base->alunos[indice];
        printf("%d - %d - %s\n", aluno->ra, aluno->telefone, aluno->nome);
    } else {
        printf("Aluno %d nao encontrado.\n", ra);
    }
}

/* Funcoes: adicionar
 *
 * Inclui um registro sem permitir RAs duplicados.
 * O quantidade de alunos deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *   telefone: numero do telefone
 *   nome: string com o nome
 */
void adicionar(Base *base, int ra, int telefone, char *nome) {
    int indice;
    if((indice = buscar(base, ra)) >= 0) {
        Aluno *aluno = &base->alunos[indice];

        // Atualizando o número de telefone e nome
        aluno->telefone = telefone;
        strcpy(aluno->nome, nome);

        printf("Alterado: ");
        imprimir(base, ra);
    } else if((base->armazenado + 1) > base->capacidade) {
        printf("Erro: base cheia.\n");
    } else {
        Aluno aluno;
        // Criando novo aluno
        aluno.ra = ra;
        aluno.telefone = telefone;
        strcpy(aluno.nome, nome);

        // Inserindo aluno
        base->alunos[base->armazenado++] = aluno;

        printf("Adicionado: ");
        imprimir(base, ra);
    }
}

/* Funcoes: remover
 *
 * Remove um registro se o ra estiver presente.
 * O quantidade de registro deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void remover(Base *base, int ra) {
    int indice;
    if((indice = buscar(base, ra)) >= 0) {
        // Passando o vetor para a esquerda (o último índice deve ser
        // (armazenado - 2))
        for(int i = indice; (i + 1) < base->armazenado; i++) {
            base->alunos[i] = base->alunos[i + 1];
        }
        base->armazenado--;

        printf("Aluno %d removido.\n", ra);
    } else {
        printf("Aluno %d nao encontrado.\n", ra);
    }
}

/* Funcao: liberar_base
 *
 * Libera a memoria de todos alunos da base.
 * Deve deixar a base com capacidade e quantidade armazenada igual a zero
 * e o ponteiro para alunos igual a NULL.
 *
 * Parametros:
 *   base: ponteiro para a base
 */
void liberar_base(Base *base) {
    free(base->alunos);
    base->alunos = NULL;
    base->armazenado = 0;
    base->capacidade = 0;
}
