#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Argumentos invalidos. Use:\n");
    fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
    fprintf(stderr, "Usado:");
    for (int i=0; i<argc; i++) {
	fprintf(stderr, " %s", argv[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }
  char efeito[20];
  char *arqEntrada = argv[1];
  char *arqSaida = argv[2];

  scanf("%s", efeito);








  return 0;
}
