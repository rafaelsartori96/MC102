#include <stdio.h>
#include <stdlib.h>


void f1(int v[], int n, int *a){
    int i;
    *a = v[0]; // main.h recebe 14

    for(i = 1; i < n; i++){
        if(v[i] % 2 == 0 && (*a) < v[i])
            *a = v[i];
        /*
        * *a não vira 8 pois *a é maior
        * *a vira 20 pois 14 < 20
        * *a não vira 2, pois *a é maior
        */
    }
}

int main(){
    int v[] ={14, 7, 8, 51, 13, 20, 2};
    int h = 15;

    f1(v, 7, &h);
    printf("h = %d\n", h); // h deve ser 20 => correto!
}
