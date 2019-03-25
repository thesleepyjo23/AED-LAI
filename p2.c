/*  AED 2018-2019, sem.2
 *  Outline main function for LabAval Problem 2
 *  Last change abl 2019.03.18
 */
#include <stdio.h>
#include <stdlib.h>
/*#include <malloc.h>*/
#include <math.h>

typedef struct _matriz {
    int linhas;
    int colunas;
    int **matriz;
} Matriz;

void funcao(Matriz *M, int *a1, int *a2)
{
    /* to write during the lab                               */
    int i, j;
    int accum=0;

    for(i=0; i<M->linhas; i++)
        for(j=0; j<M->colunas; j++)
            accum+= M->matriz[i][j];

    *a1=accum;

    accum=0;

    for(i=0; i<M->linhas; i++)
        for(j=0; j<M->colunas; j++)
            accum+=abs(M->matriz[i][j]);
            

    *a2=accum;

}


int main(int argc, char *argv[])
{
    int i, j;
    int out1, out2;
    Matriz MAT;
    FILE *fpin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    /* open file and read dimensions */
    fpin = fopen(argv[1], "r");
    fscanf(fpin, "%d %d", &MAT.linhas, &MAT.colunas);

    /* allocate memory, set structure, read in array       */
    MAT.matriz = (int **) malloc( MAT.linhas*sizeof(int*) );
    for(i=0; i<MAT.linhas; i++)
        MAT.matriz[i]= (int*) malloc( MAT.colunas*sizeof(int));
    /*...        ...       ...       ...        ...        */

    for (i = 0; i < MAT.linhas; i++) {
        for (j = 0; j < MAT.colunas; j++) {
            fscanf(fpin, "%d", &MAT.matriz[i][j]);
        }
    }
    /* apply function and print results                    */
    funcao(&MAT, &out1, &out2);

    printf("%d %d \n", out1, out2);

    /* free memory */
    for(i=0; i<MAT.linhas; i++)
        free(MAT.matriz[i]);

    free(MAT.matriz);
    /* ... */

    exit(0);
}
