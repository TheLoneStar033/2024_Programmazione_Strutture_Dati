#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "item.h"


int Returncountch(Stack s,int c){
    if(isEmptyStack(s))
    return c;

    Item item=top(s);
    //outputItem(item);
    pop(s);
    
    //CONVERSIONE
    char *sd;
    sd=(char *)item;
    printf("%c",*sd);

    //VERIFICA ALFANUM E AUMENTO CONTATORE
    if(isalnum(*sd))
    c++;

    //printf("count: %d ",c);
    Returncountch(s,c);
}

int main() {
    Stack stack=newStack();

    int n=4;
    for(int i=0;i<n;i++){
        Item item=inputItem();
        push(stack,item);
    }
    int c=0;
    //printStack(stack);
    
    int d=Returncountch(stack,c);
    printf("%d\n",d);

    

}
