#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(char x){
    char *temp=malloc(sizeof(char));
    *temp=x;

    return temp;
}


void outputItem(Item item){

    char *carattere=item;
    printf("%c", carattere);
   
}


int cmpItem(Item item1, Item item2) {
    char *a = item1;
    char *b = item2;
    return a - b;
}