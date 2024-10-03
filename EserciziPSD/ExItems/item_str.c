
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define NCHAR 20

Item inputItem(){//prende un item e lo stampa

    //La malloc deve sapere qaunto spazio allocare a un array di caratteri e quindi usiamo una define
    char *pString=malloc(NCHAR*sizeof(char));//puntatore ad intero, l'item è un puntatore e per non avere un segmentation fault c'è bisogno di allocarlo alla memoria
    
    scanf("%s", pString);//leggiamo una stringa
    
    return pString;
}


void outputItem(Item item){

    char *pString=item; //prendiamo l'item e lo assegnamo a un puntatore intero
    //facciamo questo perchè l'item non può essere deferenziato

    printf("%s ", pString);

}


int cmpItem(Item item1, Item item2){//prende due item e li confronta

//assegnamo a due puntatori ad interi
    char *pString1 = item1;
    char *pString2 = item2;

    return strcmp(pString1, pString2);//se il risultato è negativo, il primo è minore del secondo, se è 0 sono uguali, se è positivo allora il primo è maggiore del secondo

}