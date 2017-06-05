#include <stdio.h>
#include <stdlib.h>

/*
------------------------------------------------------------------------------------------------------------
Aluno(a): Rafael Sartori Martins dos Santos
RA: 186154
------------------------------------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------------------------------------
void ordena(int *conj, int tam);


Esta funcao deve ordenar um conjunto dado como parametro.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;

------------------------------------------------------------------------------------------------------------
*/

void ordena(int *conj, int tam) {
    if(conj != NULL)
        // Devemos realizar o laço interno tam - 1 vezes
        for(int it = 1; it <= tam - 1; it++)
            // Para cada elemento, trocamos de lugar com o vizinho caso este
            // seja menor
            for(int i = 0; i < tam - 1; i++) {
                if(conj[i] > conj[i + 1]) {
                    // Fazemos a troca
                    int auxiliar = conj[i];
                    conj[i] = conj[i + 1];
                    conj[i + 1] = auxiliar;
                }
            }
}

/*
------------------------------------------------------------------------------------------------------------
int pertence(int *conj, int tam, int elemento);


Esta funcao deve verificar se um elemento esta presente no conjunto.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;
- elemento -> Elemento no qual deve ser ser verificado se esta presente no conjunto;

Retorno

- 1 Caso o elemento PERTENCA conjunto;
- 0 Caso o elemento NAO PERTENCA ao conjunto;

------------------------------------------------------------------------------------------------------------
*/

int pertence(int *conj, int tam, int elemento) {
    if(conj != NULL) {
        for(int i = 0; i < tam; i++) {
            if(*(conj + i) == elemento)
                return 1;
        }
    }
    return 0;
}

/*
------------------------------------------------------------------------------------------------------------
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);


Esta funcao deve verificar se o conjunto A esta contido no conjunto B.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;

Retorno

- 1 Caso o conjunto A ESTEJA CONTIDO no conjunto B;
- 0 Caso o conjunto A NAO ESTEJA CONTIDO no conjunto B;

------------------------------------------------------------------------------------------------------------
*/

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {
    if(conj_B != NULL) {
        // Todo conjunto sem elementos está contido em outro
        if(conj_A == NULL || tam_A == 0)
            return 1;

        // Não estará contido se algum elemento de A não pertencer a B
        for(int i = 0; i < tam_A; i++) {
            if(!pertence(conj_B, tam_B, *(conj_A + i)))
                return 0;
        }

        // Não encontramos nenhum elemento que não esteja em B
        return 1;
    }
    return 0;
}

/*
------------------------------------------------------------------------------------------------------------
int* init(int *tam, int *cap);
conj_A

Esta funcao deve inicializar um vetor(conjunto).

Parametros:
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;

OBS:
- A capacidade inicial do vetor(conjunto) deve ser 2.
- O quantidade inicial de elementos no vetor(conjunto) deve ser zero.
- Nao confundir capacidade com quantidade de elementos.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* init(int *tam, int *cap) {
    int *conj = NULL;
    conj = malloc(2 * sizeof(int));
    *tam = 0;
    *cap = 2;
    return conj;
}

int *realloc_copy(int *conj, int *tam, int *cap, int newCap) {
    // Guardamos o ponteiro antigo
    int *conj_new = NULL;
    // Alocamos um vetor com a capacidade sendo newCap, substituindo conj
    conj_new = malloc((newCap) * sizeof(int));
    *cap = newCap;
    // Copiamos o vetor antigo
    for(int i = 0; i < *tam; i++) {
        *(conj_new + i) = *(conj + i);
    }
    // Liberamos o ponteiro do antigo
    free(conj);
    return conj_new;
}

/*
------------------------------------------------------------------------------------------------------------
int* adicao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve adicionar um novo elemento no conjunto, ou seja, se o elemento ja pertence ao
conjunto o mesmo NAO deve ser adicionado.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser adicionado;

OBS:
- Ao adicionar um novo elemento o tamanho atual do conjunto devera ser atualizado;
- Caso o ponteiro para o conjunto seja NULL, o conjunto devera ser alocado com uma capacidade de dois (02)
e a atualizacao da capacidade deverar ser feita;
- Caso a quantidade de elementos do conjunto seja igual a capacidade do conjunto e um novo elemento tenha que
ser inserido, então o conjunto tera de ser realocado com o dobro da capacidade e a capcidade do conjunto
devera ser atualizada;

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* adicao(int *conj, int *tam, int *cap, int elemento) {
    if(conj != NULL) {
        if(!pertence(conj, *tam, elemento)) {
            // Corrigimos seu tamanho
            if(*(tam) >= *cap)
                // Já iremos atualizar tam e cap, assim como o vetor conj
                conj = realloc_copy(conj, tam, cap, 2 * (*cap));

            // Adicionando o elemento
            *(conj + (*tam)) = elemento;
            (*tam)++;
        }
    } else {
        printf("adicao feita em vetor não inicializado!\n");
    }
    return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* subtracao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve remover um elemento no conjunto caso ele exista.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser removido;

OBS:
- Ao remover um elemento o tamanho atual do conjunto devera ser atualizado;
- Caso a capacidade seja maior que dois (02) e a quantidade de elementos do conjunto seja menor ou igual que 1/4 da capacidade do conjunto, então
o conjunto tera de ser realocado com a metade da capacidade e a capacidade do conjunto devera ser atualizada.

Dúvida:
- se 'elemento' não pertencer a 'conj', devemos atualizar seu tamanho?

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* subtracao(int *conj, int *tam, int *cap, int elemento) {
    if(conj != NULL) {
        // Removendo elemento
        if(pertence(conj, *tam, elemento)) {
            for(int i = 0; i < *tam; i++) {
                if(*(conj + i) == elemento) {
                    // Removemos o elemento, passamos todos os elementos posteriores
                    // para trás
                    for(int j = i; j < *tam - 1; j++) {
                        *(conj + j) = *(conj + j + 1);
                    }
                    (*tam)--;
                    break;
                }
            }

            // Corrigimos seu tamanho
            if(*cap > 2 && *(tam) <= ((*cap) / 4)) {
                // Já iremos atualizar tam e cap, assim como o vetor conj
                conj = realloc_copy(conj, tam, cap, (*cap) / 2);
            }
        }
    } else {
        printf("subtracao feita em vetor não inicializado!\n");
    }
    return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a uniao entre os conjuntos A e B. O resultado dessa uniao deve ser armazenado em
um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
    int *conj_C = NULL;
    conj_C = init(tam_C, cap_C);

    for(int i = 0; i < tam_A; i++) {
        conj_C = adicao(conj_C, tam_C, cap_C, *(conj_A + i));
    }

    for(int i = 0; i < tam_B; i++) {
        conj_C = adicao(conj_C, tam_C, cap_C, *(conj_B + i));
    }

    return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a intersecao entre os conjuntos A e B. O resultado dessa intersecao deve ser
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
    int *conj_C = NULL;
    conj_C = init(tam_C, cap_C);

    for(int i = 0; i < tam_A; i++) {
        // Adicionar aquele que também está em B
        if(pertence(conj_B, tam_B, *(conj_A + i)))
            conj_C = adicao(conj_C, tam_C, cap_C, *(conj_A + i));
    }

    return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a diferenca entre os conjuntos A e B. O resultado dessa diferenca deve ser
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
    int *conj_C = NULL;
    conj_C = init(tam_C, cap_C);

    for(int i = 0; i < tam_A; i++) {
        // Apenas adicione se estão em A e não em B
        if(!pertence(conj_B, tam_B, *(conj_A + i)))
            conj_C = adicao(conj_C, tam_C, cap_C, *(conj_A + i));
    }

    return conj_C;
}
