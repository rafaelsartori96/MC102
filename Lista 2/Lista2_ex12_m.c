#include <stdio.h>

int main() {
    int c;
    printf("Encontraremos as soluções para\nx1 + x2 + x3 + x4 = c\nEntre com um valor natural c: ");
    scanf("%d", &c);

    for(int x1 = 0; x1 <= c; x1++) {
        for(int x2 = 0; x2 <= c - x1; x2++) {
            for(int x3 = 0; x3 <= c - x1 - x2; x3++) {
                int x4 = (c - x1 - x2 - x3);
                if((x1 + x2 + x3 + x4) == c)
                    printf("%d + %d + %d + %d = %d\n", x1, x2, x3, x4, c);
            }
        }
    }
}
