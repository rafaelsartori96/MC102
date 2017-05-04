#include <stdio.h>
#include <string.h>

int main() {
    char palavraInicial[50], palavraFinal[50];

    printf("Diremos se é possível obter a segunda palavra a partir da primeira.\nEntre com a primeira palavra: ");
    scanf("%s", palavraInicial);
    printf("Entre com a segunda palavra: ");
    scanf("%s", palavraFinal);

    for(int i = 0, j = 0; i < strlen(palavraInicial); i++) {
        // Se encontramos uma letra que corresponde à da palavra final
        if(tolower(palavraInicial[i]) == tolower(palavraFinal[j])) {
            // Procuramos a próxima letra
            j++;

            // Se achamos todos as letras de palavraFinal, conseguimos fazer a
            // palavra final a partir da primeira
            if(palavraFinal[j] == '\0') {
                printf("É possível adiquirir a segunda palavra partindo da primeira.\n");
                return 0;
            }
        }
    }

    printf("Não é possível conseguir a segunda palavra a partir da primeira.\n");
}
