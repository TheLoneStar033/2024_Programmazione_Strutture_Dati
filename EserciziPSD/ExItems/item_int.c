
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){//prende un item e lo stampa

    int *pInt=malloc(sizeof(int));//puntatore ad intero, l'item è un puntatore e per non avere un segmentation fault c'è bisogno di allocarlo alla memoria
    
    scanf("%d", pInt);
    
    return pInt;
}


void outputItem(Item item){

    int *pInt=item; //prendiamo l'item e lo assegnamo a un puntatore intero
    //facciamo questo perchè l'item non può essere deferenziato

    printf("%d ", *pInt);

}


int cmpItem(Item item1, Item item2){//prende due item e li confronta

//assegnamo a due puntatori ad interi
    int *pInt1 = item1;
    int *pInt2 = item2;

    return (*pInt1 - *pInt2);//se il risultato è negativo, il primo è minore del secondo, se è 0 sono uguali, se è positivo allora il primo è maggiore del secondo

}