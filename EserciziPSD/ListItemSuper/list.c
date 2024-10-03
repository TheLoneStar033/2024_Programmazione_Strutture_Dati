#include <stdlib.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};


List newList(){
    List list=malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    
    return list;
}

int isEmpty(List list){
    return list->size==0;
}

void addHead(List list, Item item){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list){
    if (isEmpty (list)) return NULL;
    struct node *temp= list->head;
    list->head = temp->next;
    Item item = temp->value;
    free (temp);
    list->size--;
    return item;
}

Item getHead(List list){
    if (isEmpty (list)) return NULL;
    return list->head->value;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head; p!=NULL; p=p->next)
        outputItem(p->value);

}

Item searchListItem(List list, Item item, int *pos){

    struct node *p;
    *pos=0;

    for(p=list->head; p!=NULL; p=p->next){

        if(cmpItem(item, p->value)==0){
            return p->value;
        }
        (*pos)++; //senza parentesi qui viene effettuato invece che un incremento del valore un incremento dell'indirizzo
    }

//se non si verifica il for non trova il carattere e restituisce null
    *pos = -1;
    return NULL;
}

Item removeListItem(List list, Item item){

    Item temp;//item temporaneo

    if(isEmpty(list)){
        return NULL;
    }

    struct node *p, *prev;//*prev punta al nodo precedente a quello da eliminare    

    for(p=list->head; p!=NULL; prev=p, p=p->next){

        if(cmpItem(item, p->value)==0){

            //scrivo un if per gestire il caso in cui va rimossa la testa
            if(p==list->head){//se il puntatore si trova direttamente sulla testa della lista, utilizziamo direttamente la funzione che rimuove la testa della lista
           
            return removeHead(list);//così da restituire la nuova lista senza la testa
            }

            prev->next = p->next;
            temp = p->value;
            free (p);//per eliminare il nodo puntato da p
            list->size--;
            return temp;

        }
        
    }

    return NULL;//se il for è finito e non troviamo niente


}
Item removeListPos(List list, int pos){

    Item temp;//item temporaneo
    int cont=0;

    if(isEmpty(list) || pos<0 || pos>=sizeList(list)){//verifica della precondizione
        return NULL;
    }

    struct node *p, *prev;//*prev punta al nodo precedente a quello da eliminare    

    for(p=list->head; p!=NULL; prev=p, p=p->next){

        if(pos==cont){

            //scrivo un if per gestire il caso in cui va rimossa la testa
            if(p==list->head){//se il puntatore si trova direttamente sulla testa della lista, utilizziamo direttamente la funzione che rimuove la testa della lista
            
            return removeHead(list);//così da restituire la nuova lista senza la testa
            }

            prev->next = p->next;
            temp = p->value;
            free (p);//per eliminare il nodo puntato da p
            list->size--;
            return temp;

        }
        
        cont++;
        
    }

    return NULL;//se il for è finito e non troviamo niente



}

