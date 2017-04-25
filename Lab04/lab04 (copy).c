#include <stdio.h>

/*int fat(int n) {
    if(n <= 1)
        return 1;
    return n * fat(n - 1);
}

int comb_n_p(int n, int p) {
    return fat(n) / (p * fat(n - p));
}

int num_combinacoes(int n) {
    int num_combinacoes;
    num_combinacoes = 0;
    for(int p = 1; p <= n; p++)
        num_combinacoes += comb_n_p(n, p);
    return num_combinacoes;
}


/*
 * Author: Rafael Sartori Martins dos Santos(RA: 186154)
 *
 * O programa receberá 4 inteiros que representarão os pesos das
 * cargas que irão na nave. Se alguma das somas de 2 cargas for
 * igual a das outras duas, então a nave pode voar.
 *
 */
/*int main() {
    int num_cargas = 4;
    int cargas[num_cargas];

    if(num_cargas % 2 != 0) {
        printf("O número de cargas deve ser par.\n");
        return -1;
    }

    // Receber os valores do console.
    for(int i = 0; i < num_cargas; i++) {
        scanf("%d", &cargas[i]);
    }

    // Debug para parametrização
    {
        int first;
        first = 1;
        printf("As cargas recebidas são: ");
        for(int i = 0; i < num_cargas; i++) {
            if(!first)
                printf(", ");
            first = 0;
            printf("%d", cargas[i]);
        }
        printf("\nNúmero de combinações(n) = %d\n", num_combinacoes(num_cargas));
    }

    int possible;
    possible = 0;

    // Calculando as possíveis somas
    {
        int num_somas = num_combinacoes(num_cargas);
        int somas[num_somas];
        int ultima_soma;
        ultima_soma = 0;

        // Agora precisamos fazer as combinações:
        // De 2 em 2, 3 em 3, (...), n em n
        for(int p = 1; p <= num_cargas; p++) {
            // Em p = 1: somaremos todos únicos elementos
            // Em p = 2: somaremos todos os pares ordenados de elementos
            // ...
            // Em p = n: somaremos todos os n elementos



            somas[ultima_soma++] = somas[i]; // ao menos um elemento
            // Agora precisamos fazer as combinações de 2 em 2, 3 em 3, (...) até n-1 em n-1.
            for(int j = 2; j < n; j++) {
                int soma_atual;
                soma_atual = somas[i];


                somas[ultima_soma++] = soma_atual;
            }
            for(int j = num_cargas - 1; j > i; j--) {
                printf("%d, %d\n", i, j);
                somas[ultima_soma++] = cargas[i] + cargas[j];
            }
        }

        // Determinando se alguma das somas resulta em outra
        for(int i = 0; i < num_somas; i++) {
            for(int j = num_somas - 1; j < num_somas && j != i; j--) {
                printf("(soma(%d) = %d) == (soma(%d) = %d)? %d\n", i, somas[i], j, somas[j], somas[i] == somas[j]);
                if(somas[i] == somas[j]) {
                    possible = 1;
                    printf("sim\n");
                    return 0;
                }
            }
        }
    }

    printf("nao\n");
    return 0;
}
*/
int main() {
    int c1, c2, c3, c4;
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);

    if(c1 + c2 == c3 + c4)
        printf("sim\n");
    else if(c1 + c3 == c2 + c4)
        printf("sim\n");
    else if(c1 + c4 == c2 + c3)
        printf("sim\n");
    else if(c1 == c2 + c3 + c4)
        printf("sim\n");
    else if(c2 == c1 + c3 + c4)
        printf("sim\n");
    else if(c3 == c1 + c2 + c4)
        printf("sim\n");
    else if(c4 == c1 + c2 + c3)
        printf("sim\n");
    else
        printf("nao\n");
}
