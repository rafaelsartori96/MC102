#include <stdio.h>
#include <stdlib.h>


int menor_base_log(int n, int *b, int *k) {
    // Faremos os laços de valores possíveis de b e k
    for(int b_ = 2; b_ <= n; b_++) {
        for(int k_ = 1; k_ <= n; k_++) {
            int potencia = b_;

            // Agora, elevamos b_ a k_
            for(int i = 0; i < k_; i++)
                potencia *= b_;

            if(potencia == n) {
                // Passando os valores, retornando sucesso
                *b = b_;
                *k = k_;
                return 1;
            }
        }
    }
    // Caso chegamos aqui, não encontramos
    return 0;
}

int main() {
    int b, k, n;
    printf("Encontraremos um par (b, k) tal que:\n");
    printf("b^k = n\n");
    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    if(menor_base_log(n, &b, &k)) {
        printf("%d^%d = %d\n", b, k, n);
    } else {
        printf("Não encontramos o par (b, k) tal que b^k = %d!\n", n);
    }
}
