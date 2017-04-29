//
// Created by jabyftw on 10/03/17.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c, area;
    printf("Entre os lados do triângulo (a, b, c) = ");
    scanf("%f %f %f", &a, &b, &c);
    // Checando se (a, b, c) é triângulo
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Triângulos não podem ter lados negativos.\n");
        return -1;
    }
    if (
            !((a >= b && a >= c && a <= (b + c))
              || (b >= a && b >= c && b <= (a + c))
              || (c >= a && c >= b && c <= (b + a))
            )) {
        printf("Esses valores não respeitam a desigualdade triângular.\n");
        return -1;
    }

    printf("Os lados do triângulo valem a=%.2f, b=%.2f e c=%.2f.\n", a, b, c);
    // Conferindo qual o tipo do triângulo.
    printf("Disso, tiramos que o triângulo é ");
    if (a == b && b == c)
        printf("equilátero.\n");
    else if ((a == b && b != c) || (a == c && b != c) || (a != b && b == c))
        printf("isóceles.\n");
    else
        printf("escaleno.\n");
    // Calculando a área
    float s;
    s = (a + b + c) / 2.0f;
    printf("s=%.3f A^2=%.3f\n", s, s * (s - a) * (s - b) * (s - c));
    area = (float) sqrt(s * (s - a) * (s - b) * (s - c));
    printf("A área A do triângulo é %.3f e o perímetro é %.2f.\n", area, 2.0 * s);
    return 0;
}