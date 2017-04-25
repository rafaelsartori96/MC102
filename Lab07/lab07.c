#include <stdio.h>

/*
 * Rafael Sartori Martins dos Santos (RA: 186154)
 *
 * O programa retornará todas as trincas que representam um
 * triângulo pitagórico de números inteiros (multiplos de 3,
 * 4, 5) para um dado a:
 *
 * (a, b, c)
 *
 */
int main() {
    int a, b = 1, c = 1, found = 0;
    scanf("%d", &a);

    // O limite será quando b^2 for menor que a c^2 - a^2
    while((b*b) <= (1000*1000 - a*a)) {
        if((a*a + b*b) == (c*c)) {
            printf("(%d, %d, %d)\n", a, b, c);
            found = 1;
        }

        if(c < 1000) {
            c++;
        } else {
            b++;
            c = 1;
        }
    }

    if(!found)
        printf("-\n");
}
