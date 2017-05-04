#include <stdio.h>
#include <string.h>

int main() {
    char texto[1000], palavra[50];
    int indices[500], indice = 0;

    printf("Entre com um texto de, no máximo, 1000 caracteres: ");
    fgets(texto, 1000, stdin);

    printf("Entre com a palavra a ser buscada: ");
    scanf("%s", palavra);

    int indiceInicial = -1, indiceBusca = -1;
    for(int i = 0; i < strlen(texto); i++) {
        // Primeiro, devemos determinar se estamos esperando a palavra:
        // (i) quando estamos no início do arquivo
        // (ii) quando a letra passada é um espaço
        if(texto[i] != ' ' && (i == 0 || texto[i - 1] == ' ')) {
            indiceInicial = i;
            indiceBusca = 0;
        }

        // Vamos conferir a palavra
        if(indiceBusca >= 0) {
            if(tolower(texto[i]) == tolower(palavra[indiceBusca])) {
                // Se terminamos a palavra e ela foi igual, encontramos o índice
                // da palavra
                if(indiceBusca + 1 >= strlen(palavra) &&
                (i + 1 >= strlen(texto) || texto[i + 1] == ' ')) {
                    indices[indice++] = indiceInicial;
                    indiceBusca = -1;
                } else {
                    indiceBusca++;
                }
            } else {
                // Já que a palavra não é igual, aguardamos até a próxima
                // palavra
                indiceBusca = -1;
            }
        }
    }

    printf("Índices encontrados = {");
    for(int i = 0; i < indice; i++) {
        if(i > 0)
            printf(", ");
        printf("%d", indices[i]);
    }
    printf("}\n");
}
