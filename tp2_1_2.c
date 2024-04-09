/*
modifique el código anterior para utilizar aritmética de punteros
(notación indexada) para recorrer el vector.
*/

//para quitar el proxy: git config --global --unset https.proxy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
    srand(time(NULL));
    int i;
    double vt[N];
    double *p = vt;
    for(i = 0;i<N; i++)
    {
        *(p+i)=1+rand()%100;
        //printf("elemento normal %d: %f \n ", i, vt[i])
        printf("elemento puntero %d: %f \n ", i, *(p+i));
    }

    return 0;
}
