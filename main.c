#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    clock_t t;
    int **x;
    int **y;
    int nl, nc, i, j;
    nl=10;
    nc=10;

    //Aloca o array auxiliar x
    x=(int**)malloc(nl*sizeof(int*));

    //Aloca do espaço de memória para x
    x[0]=(int*)malloc(nl*nc*sizeof(int));

    //Aloca o array auxiliar y
    y=(int**)malloc(nl*sizeof(int*));

    //Aloca do espaço de memória para y
    y[0]=(int*)malloc(nl*nc*sizeof(int));

    //Aloca o restante da matriz para x
    for (i=1; i<nl; i++){
        x[i]=x[i-1]+nc;
    }

    //Aloca o restante da matriz para y
    for (i=1; i<nl; i++){
        y[i]=y[i-1]+nc;
    }

    t = clock();
    //Gera a matriz
    srand(time(0));
    for (i=0; i<nl; i++){
        for(j=0; j<nc; j++){
            x[i][j]=rand()%10;
        }
    }
    t = clock() - t;
    printf("tempo para efetuar a matriz foi de %f ", t, ((float)t));
    printf("\n");

    //Mostra a matriz
    for (i=0; i<nl; i++){
        for(j=0; j<nc; j++){
            printf("%2d, ", x[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    t = clock();
    //Mostra a copia da matriz(utilizando funcao memcpy)
    memcpy(y[0], x[0], nl*nc*sizeof(int));
    t = clock() - t;
    printf("tempo para efetuar a copia foi de %2f ", t);
    printf("\n");

    //Mostra a matriz
    for (i=0; i<nl; i++){
        for(j=0; j<nc; j++){
            printf("%2d, ", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}
