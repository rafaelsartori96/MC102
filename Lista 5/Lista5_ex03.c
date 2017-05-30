#include <stdio.h>
#include <stdlib.h>


int mdc(int m, int n) {
    // Fazemos ficar na forma m >= n
    if(m < n)
        return mdc(n, m);

    if(n == 0)
        return m;
    else
        return mdc(n, m % n);
}

int main() {
    int m, n;
    printf("Entre com dois números: ");
    scanf("%d %d", &m, &n);

    printf("O mdc(%d, %d) é %d.\n", m, n, mdc(m, n));
}
