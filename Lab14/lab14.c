// Rafael Sartori Martins dos Santos (RA: 186154)

#include <stdio.h>

int NAO_ORDENADO        = 0,
    ORDEM_CRESCENTE     = 1,
    ORDEM_DECRESCENTE   = 2;
int ordenacao;

void imprimir(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        // Não preciso tomar cuidad com os espaços... Maldito susy
        printf("%d ", vetor[i]);

        if(i == tamanho - 1)
            printf("\n");
    }
}

// Insertion sort
void ordenar(int vetor[], int tamanho) {
    if(ordenacao == NAO_ORDENADO)
        return;

    // Para todos os elementos vetor[i], começando com i = 1
    for(int i = 1; i < tamanho; i++) {
        // Para todos os elementos de vetor[i] a vetor[0]
        for(int j = i; j > 0; j--) {
            int trigger_bubble;

            if(ordenacao == ORDEM_CRESCENTE) {
                trigger_bubble = vetor[j - 1] > vetor[j];
            } else if(ordenacao == ORDEM_DECRESCENTE) {
                trigger_bubble = vetor[j - 1] < vetor[j];
            }

            // Fazemos o bubble sort até ordernarmos i ... 0
            if(trigger_bubble) {
                // Guardamos vetor[j - 1], pois ele é maior que vetor[j]
                int auxiliar = vetor[j - 1];
                // Tentamos deixar o vetor ordenado: colocamos quem é maior
                // à direita
                vetor[j - 1] = vetor[j];
                // e quem é menor, à esquerda
                vetor[j] = auxiliar;
            } else {
                // Já está ordenado
                break;
            }
        }
    }
}

void buscaBinaria(int vetor[], int tamanho, int busca) {
    if(ordenacao == NAO_ORDENADO)
        return;

    int inicio = 0, fim = tamanho - 1;

    while(fim >= inicio) {
        int meio = (fim + inicio) / 2;
        printf("%d ", meio);

        if(busca == vetor[meio]) {
            printf("\n%d esta na posicao: %d\n", busca, meio);
            return;
        } else {
            if(ordenacao == ORDEM_CRESCENTE) {
                // (menor elemento, ..., maior elemento)
                // Na ordem crescente, se o elemento buscado é menor que o do
                // meio alteramos o final para ser antes do meio. Se é maior do
                // que o meio, alteramos o início para ser depois do meio.
                if(busca > vetor[meio])
                    inicio = meio + 1;
                else
                    fim = meio - 1;
            } else {
                // (maior elemento, ..., menor elemento)
                // Na ordem decrescente, se o elemento buscado é maior do que o
                // meio, alteramos o final para ser antes do meio. Se é menor
                // do que o meio, alteramos o início para ser depois do meio.
                if(busca > vetor[meio])
                    fim = meio - 1;
                else
                    inicio = meio + 1;
            }

        }
    }

    // Se chegamos aqui, não encontramos
    printf("\n%d nao esta na lista!\n", busca);
}

int inserir(int vetor[], int tamanho, int num) {
    if(tamanho + 1 > 150) {
        printf("Limite de vagas excedido!\n");
        return tamanho;
    }

    for(int i = 0; i < tamanho; i++) {
        if(num == vetor[i]) {
            printf("Aluno ja matriculado na turma!\n");
            return tamanho;
        }
    }

    if(ordenacao == ORDEM_CRESCENTE) {
        for(int i = 0; i < tamanho; i++) {
            if(num < vetor[i]) {
                for(int j = tamanho; j > i; j--) {
                    vetor[j] = vetor[j - 1];
                }

                // Inserimos o número
                vetor[i] = num;
                return tamanho + 1;
            }
        }
        // Se não retornamos, ele deve ser o último número (maior que todos)
    } else if(ordenacao == ORDEM_DECRESCENTE) {
        for(int i = 0; i < tamanho; i++) {
            if(num > vetor[i]) {
                for(int j = tamanho; j > i; j--) {
                    vetor[j] = vetor[j - 1];
                }

                // Inserimos o número
                vetor[i] = num;
                return tamanho + 1;
            }
        }
        // Se não retornamos, colocaremos no final da lista (é menor que todos)
    }

    // Adicionamos o ítem no final (caso não tenha ordem, ou caso seja item de
    // extremidade).
    vetor[tamanho] = num;
    return tamanho + 1;
}

int remover(int vetor[], int tamanho, int num) {
    if(tamanho == 0)  {
        printf("Nao ha alunos cadastrados na turma!\n");
        return tamanho;
    }

    for(int i = 0; i < tamanho; i++) {
        if(num == vetor[i]) {
            // Passamos todos os elementos para a esquerda
            for(int j = i; j < tamanho; j++) {
                vetor[j] = vetor[j + 1];
            }
            return tamanho - 1;
        }
    }

    printf("Aluno nao matriculado na turma!\n");
    return tamanho;
}

int main() {
    int listaRA[150], tamanho = 0;
    ordenacao = NAO_ORDENADO;

    // Lendo a lista de R.A.s
    {
        int alunos;
        scanf("%d", &alunos);

        // Leremos todos os alunos
        for(; tamanho < alunos; tamanho++) {
            scanf("%d", &listaRA[tamanho]);
        }
    }

    // Declaração usada em alguns comandos. Não é possível declarar dentro de
    // switch-case
    int ra;
    // Executando comandos
    char comando;
    do {
        scanf("%c", &comando);

        switch (comando) {
            // Comando de impressão
            case 'p':
                imprimir(listaRA, tamanho);
                break;

            // Ordenação crescente
            case 'c':
                ordenacao = ORDEM_CRESCENTE;
                ordenar(listaRA, tamanho);
                break;

            case 'd':
                ordenacao = ORDEM_DECRESCENTE;
                ordenar(listaRA, tamanho);
                break;

            case 'b':
                // Não sei se é obrigatório ler o R.A. antes de conferir se a
                // lista está ordenada. A minha intuição diz que não, pois o
                // scanf de caracteres lerá os números e isso não terá nenhum
                // efeito no código senão desempenho
                scanf("%d", &ra);

                if(ordenacao == NAO_ORDENADO) {
                    printf("Vetor nao ordenado!\n");
                    break;
                }

                buscaBinaria(listaRA, tamanho, ra);
                break;

            case 'i':
                scanf("%d", &ra);
                tamanho = inserir(listaRA, tamanho, ra);
                break;

            case 'r':
                scanf("%d", &ra);
                tamanho = remover(listaRA, tamanho, ra);
                break;

            // Comando de saída
            case 's':
            // Padrão (qualquer letra que não representa um comando)
            default:
                break;
        }
    } while(comando != 's');
}
