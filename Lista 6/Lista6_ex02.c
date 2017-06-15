#include <stdio.h>
#include <stdlib.h>


int main() {
    // RA: 186154
    int a = 1 + 8 + 6, b = 1 + 5 + 4, *c, *d;

    c = &a;
    d = c;
    c = &b;

    if(*d % 2 == 0)
        *d = *d - 10;
    else
        *c = 2 * (*c);

    printf("a = %d, b = %d\n", a, b); // Deve ser a = 15, b = 20 => correto!
}
