#include <stdio.h>
#include <stdlib.h>

#define ID_UNKNOWN -1


typedef struct {
    int x, y;
    int identificador;
    char caractere;
} Coordenada;

typedef struct {
    int largura, altura;
    Coordenada *regiao;
} Mapa;

typedef struct ElementoCoordenadas {
    Coordenada *coordenada;
    struct ElementoCoordenadas *proximo;
} ElementoCoordenadas;


int pesquisarBase(Mapa *mapa, char caractere);

ElementoCoordenadas *buscarRegiao(Mapa *mapa, ElementoCoordenadas *lista, char caractere, int centro_x, int centro_y);

int checarCoordenadasMapa(Mapa *mapa, int x, int y);

Coordenada *posicaoMapa(Mapa *mapa, int x, int y);


int main() {
    Mapa mapa;
    // Lemos os dados de entrada do mapa
    // POR QUE INFERNOS ALTURA PRIMEIRO? vocês estão de trollagem
    scanf("%d %d ", &mapa.altura, &mapa.largura);

    // Alocamos a região do mapa
    mapa.regiao = malloc(mapa.largura * mapa.altura * sizeof(Coordenada));
    if(mapa.regiao == NULL) {
        fprintf(stderr, "Erro ao alocar memória dinâmica para a região do mapa.\n");
        return 1;
    }

    {
        // Lemos a região do mapa
        int x = 0, y = 0;
        char aux;
        do {
            scanf("%c", &aux);

            if(aux == '#' || aux == '*' || aux == '-') {
                // Adicionamos o caractere e atualizamos a coordenada
                Coordenada *coordenada = posicaoMapa(&mapa, x, y);
                coordenada->x = x;
                coordenada->y = y;
                coordenada->identificador = -1;
                coordenada->caractere = aux;

                if(++x >= mapa.largura) {
                    x = 0;
                    y++;
                }
            }
        } while(y < mapa.altura);
    }

    // Executamos o código
    printf("Bases rebeldes: %d\n", pesquisarBase(&mapa, '#'));
    printf("Bases do imperio: %d\n", pesquisarBase(&mapa, '*'));

    // Agora que terminamos o programa, podemos liberar a memória alocada dinâ-
    // micamente
    free(mapa.regiao);
}

ElementoCoordenadas *buscarRegiao(Mapa *mapa, ElementoCoordenadas *lista, char caractere, int centro_x, int centro_y) {
    for(int offset_y = -1; offset_y <= 1; offset_y++) {
        for(int offset_x = -1; offset_x <= 1; offset_x++) {
            int x = centro_x + offset_x,
                y = centro_y + offset_y;

            // Pulamos as coordenadas que não são válidas
            if(!checarCoordenadasMapa(mapa, x, y))
                continue;

            // Pulamos o centro (? devemos pular o centro?)
            // RESPOSTA: não pulamos o centro pois queremos que ele esteja na
            // lista para definirmos o seu identificador
            /*if(centro_x == x && centro_y == y)
                continue;*/

            {
                // Pulamos coordenadas que já estão na lista
                int pertence = 0;
                ElementoCoordenadas *elemento_aux = lista;
                while(elemento_aux != NULL) {
                    Coordenada *coordenada_aux = elemento_aux->coordenada;
                    // Conferimos se é o elemento atual
                    if(coordenada_aux->x == x && coordenada_aux->y == y) {
                        pertence = 1;
                        break;
                    }

                    // Buscamos o próximo elemento
                    elemento_aux = elemento_aux->proximo;
                }
                // Se pertence, continuamos a busca de vizinhos
                if(pertence == 1)
                    continue;
            }

            Coordenada *vizinho = posicaoMapa(mapa, x, y);
            // Pulamos o vizinho que não possui o caractere desejado
            if(vizinho->caractere != caractere)
                continue;

            // Pulamos o vizinho que já foi registrado
            if(vizinho->identificador != ID_UNKNOWN)
                continue;

            // Como o elemento possui mesmo caractere e é um vizinho, adiciona-
            // mos à lista
            {
                ElementoCoordenadas *aux = lista;
                lista = malloc(sizeof(ElementoCoordenadas));
                if(lista == NULL) {
                    fprintf(stderr, "Erro ao alocar memória dinâmica para um elemento da lista.\n");
                    while(aux != NULL) {
                        // Para limpar aux atual (que começa com o antigo início
                        // da lista), guardamos o próximo elemento
                        ElementoCoordenadas *free_ = aux->proximo;
                        free(aux);
                        // Agora, enquanto a lita não tiver acabado, liberaremos
                        // os próximos elementos
                        aux = free_;
                    }
                    return NULL;
                }

                // Atualizamos o elemento da lista, adicionando vizinho e mes-
                // clamos o resto da lista
                lista->coordenada = vizinho;
                lista->proximo = aux;
            }

            // Agora, já que estamos em um vizinho, temos que conferir seus
            // vizinhos:
            if(x == centro_x && y == centro_y)
                continue;

            lista = buscarRegiao(mapa, lista, caractere, x, y);
        }
    }

    return lista;
}

int pesquisarBase(Mapa *mapa, char caractere) {
    int identificador = 0;
    for(int y = 0; y < mapa->altura; y++) {
        for(int x = 0; x < mapa->largura; x++) {
            Coordenada *posicao = posicaoMapa(mapa, x, y);
            // Conferimos se o elemento possui o caractere que procuramos
            if(posicao->caractere != caractere)
                continue;

            // Pulamos elementos que já estão registrados
            if(posicao->identificador != ID_UNKNOWN)
                continue;

            // Vemos todos os vizinhos possíveis
            ElementoCoordenadas *lista = buscarRegiao(mapa, NULL, caractere, x, y);

            // Usando a lista de vizinhos, definimos um identificador para os
            // elementos
            ElementoCoordenadas *elemento = lista, *aux;
            while(elemento != NULL) {
                elemento->coordenada->identificador = identificador;

                // Liberamos a lista que utilizamos, para isso, guardaremos o
                // próximo elemento
                aux = elemento;
                elemento = aux->proximo;
                free(aux);
            }
            // Agora que atribuímos um identificador a todos, incrementamos o
            // identificador para a nova busca
            identificador++;
        }
    }
    // Como projetamos o identificador para começar por zero, ele será também o
    // número de bases de dado caractere.
    return identificador;
}

int checarCoordenadasMapa(Mapa *mapa, int x, int y) {
    return x >= 0 && x < mapa->largura && y >= 0 && y < mapa->altura;
}

Coordenada *posicaoMapa(Mapa *mapa, int x, int y) {
    if(!checarCoordenadasMapa(mapa, x, y)) {
        fprintf(stderr, "Erro ao acessar posição (%d, %d) no mapa.\n", x, y);
        return NULL;
    }

    return (mapa->regiao + (y * mapa->largura) + x);
}
