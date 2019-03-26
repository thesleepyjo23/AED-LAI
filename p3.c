/*  AED 2018-2019, sem.2
 *  Outline main function for LabAval Problem 3
 *  Last change abl 2019.03.19
 */
#include <stdio.h>
#include <stdlib.h>
/*#include <malloc.h>*/
#include <math.h>
#include <limits.h>

#include"LinkedList.h"

#define DEBUG
int  compareItems(Item it1, Item it2)
{
    int i1, i2;

    i1 = *((int *) it1);
    i2 = *((int *) it2);

    if (i1 < i2)
        return -1;
    if (i1 > i2)
        return 1;
    return 0;
}

void freeEntryItem(Item item)
{
    return;       /* no mem actually allocated */
}

/* define ratio of data items, N, to buckets, M, according to taste */
#define NMR 4

/*
 *  Function:
 *    bucketSort()
 *
 */
void bucketSort(int *vtab, LinkedList **btab,
                    int bcnt, int vcnt, int vmin, int vmax)
{
    int i, idx=0;
    LinkedList *lp;
    int err;

    LinkedList *aux;

    /*inicia todas as listas como NULL*/
    for (i=0; i < bcnt; i++)
    {
        lp = initLinkedList();
        btab[i] = lp;
    }
   
    /*preencher as listas com os valores*/ 
    for (i=0; i < vcnt; i++)
    {
        idx=(bcnt*vtab[i])/(vmax+1);
        btab[idx]=insertSortedLinkedList(btab[idx], (Item) &(vtab[i]), compareItems, &err);
        aux = btab[idx];
    }

    printf("\nLista imprimida de forma crescente:\n");
    /* Impressão da lista */
    for (i=0; i < bcnt; i++){
        aux = btab[i];

        while(aux != NULL){
            printf("%d\n", *((int *) getItemLinkedList(aux)));
            aux = getNextNodeLinkedList(aux);
        }

    }

    for (i=0; i < bcnt; i++)
        freeLinkedList(btab[i], freeEntryItem);
    
   
}


 /*
 *  Function:
 *    main()
 *
 */
int main(int argc, char *argv[])
{
    int ibuf, i;
    int *vtab;              /* data values table   */
    int vcnt = 0;
    int vmin = INT_MAX;
    int vmax = INT_MIN;     /* not a bug */
    LinkedList **btab;
    int  bcnt;              /* size of bucket table */
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    fp = fopen ( argv[1], "r" );
    if ( fp == NULL ) {
        fprintf ( stderr, "ERROR: cannot open file '%s'\n", argv[1]);
        exit ( 1 );
    }

    /* first scan: count int values, find min and max */
    while(fscanf(fp, "%d", &ibuf) == 1) {
        vcnt++;
        if (ibuf > vmax)    vmax = ibuf;
        if (ibuf < vmin)    vmin = ibuf;
    }
    printf("Read %d ints, min = %d, max = %d\n", vcnt, vmin, vmax);     

    /* allocate memory for int value table   */
    vtab = (int *) malloc( vcnt * sizeof(int) );
    
    /* second scan: store int values */
    rewind(fp);
    for (i=0; i < vcnt; i++) {
        fscanf(fp, "%d", &(vtab[i]) );
    }
    fclose(fp);

    /* allocate bucket table (with at least one bucket) */

    bcnt = 1 + vcnt / NMR;
    btab = (LinkedList **) malloc (bcnt * sizeof(LinkedList *));
    
    /* call bucket sort, print result  */

    bucketSort(vtab, btab, bcnt, vcnt, vmin, vmax);


    /* free memory */

    free(vtab);
    free(btab);
    /* ... */

    exit(0);
}
