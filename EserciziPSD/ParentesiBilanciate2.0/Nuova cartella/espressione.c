#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "stack.h"

int isOpen(char ch)
{
    if((ch=='(') || (ch=='[') || (ch=='{'))
        return 1;
    else
        return 0;
}

int isClosed(char ch)
{

    if((ch==')') || (ch==']') || (ch=='}'))
        return 1;
    else
        return 0;
}

int isCorresponding(char ch1, char ch2)
{
    if(ch1==(ch2-1))//Parentesi Tonde
        return 1;
    else if(ch1==(ch2-2))//Parentesi Quadre e Graffe
            return 1;
        else return 0;
}

int isBalanced(char *exp)
{

    Stack stack=newStack();

    for(;*exp!='\0'; exp++)
    {
        if(isOpen(*exp)){//se il valore della stringa è una parentesi aperta
        //trasforma questo exp[1] in un item e immettilo nello stack

            //---------TRASFORMAZIONE CHAR IN ITEM------------
            Item item=malloc(sizeof(Item));
            item=exp;
            push(stack, item);
        }
        else if(isClosed(*exp))//altrimenti se è una parentesi chiusa
        {  
            if(isEmptyStack(stack))
                return 0;
            else
            {
            char *chv=top(stack);  //Salviamo il valore del top dello stack ossia l'ultimo valore inserito
                if (isCorresponding(*chv, *exp)) //lo passiamo alla funzione iscorresponding e vediamo se vi è una parentesi corrispondente
                        pop(stack);
                else
                    return 0;
            }
                
        }
                

    }
    if(isEmptyStack(stack)) return 1; //se lo stack è vuoto ossia che ogni parentesi aperta è stata rimossa significa che 
    //per ogni parentesi aperta ne corrisponde una chiusa quindi l'espressione è bilanciata.
}