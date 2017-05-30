#include <stdio.h>
#include <stdlib.h>


int testePitagorico(int a, int b, int n) {
    return a * a + b * b == n;
}

int pitagorico(int n) {
    for(int a = 1; a < n; a++) {
        for(int b = 1; b < n; b++) {
            if(testePitagorico(a, b, n)) {
                printf("n é pitagórico, pois %d^2 + %d^2 = %d.\n", a, b, n);
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int n;
    printf("Entre com um número: ");
    scanf("%d", &n);

    printf(pitagorico(n) ? "%d é pitagórico.\n" : "%d não é pitagórico.\n", n);
}
