#include <stdio.h>
#include <stdlib.h>

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
  /* Implementar */
  return;
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
  /* Implementar */
  return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {
  /* Implementar */
  return;
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
  /* Implementar */
  return;
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
  /* Implementar */
  return;
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
  /* Implementar */
  return;
}
