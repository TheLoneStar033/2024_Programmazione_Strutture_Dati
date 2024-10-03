#include <stdlib.h>
#include "list.h"
#include "item.h"
#include <stdio.h>


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
void ListFilterFilt(List *list,Item item){
    (*list)=ListFilter(list,item);
}

List ListFilter(List *list,Item item)
{
    char *it1[20], *it2[20];
    struct node *p, *prev;//*prev punta al nodo precedente a quello da eliminare    
    it2[1]=item;
    List listfilt=newList();

    for(p=(*list)->head; p!=NULL; prev=p, p=p->next){

        //if(cmpItem(item, p->value)==0)
        //printf("sus");
        it1[1]=p->value;

        if((*it2[1])!=(*it1[1])){
        //removeListItem((*list),p->value);
        addHead(listfilt,p->value);
       
        //printf("%c",(*it2[1]));
        //printf("%c",(*it1[1]));
        }
        
    }
    //printList(listfilt);
    return listfilt;
}

/*

void ListFilter2(List *list,Item item)//ROTTO
{
    char *it1[20], *it2[20];
    struct node *p, *prev;//*prev punta al nodo precedente a quello da eliminare    
    it2[1]=item;
    //List listfilt=newList();

    for(p=(*list)->head; p!=NULL; prev=p, p=p->next){

        //if(cmpItem(item, p->value)==0)
        //printf("sus");
        it1[1]=p->value;

        if((*it2[1])==(*it1[1]))
        {
        removeListItem((*list),p->value);
        printList((*list));
        prev = p; // Update prev to the current node before removing it
        } 
        else 
        {
            prev = p; // Update prev to the current node if no removal is made
        }
        
        //printf("%c",(*it2[1]));
        //printf("%c",(*it1[1]));
        }
        
    }
*/

void reverseList(List *list){
    List listrev =newList();
    struct node *p, *prev,*temp;
    for(p=(*list)->head; p!=NULL ; prev=p , p=temp)
    {
        printf("reversing");
        temp=p->next;
        p->next = prev;
    }
    (*list)->head=prev;

}

int addListPos(List list, Item item, int pos){
	if(pos<0 || pos>sizeList(list)){
		return 0;
	}
	
	if(pos==0){
		addHead(list,item);
		return 1;
	}
	
	struct node *p,*newNode;
	int i=0;
    for (p=list->head; p!=NULL && i<pos-1; p=p->next,i++);
	newNode=malloc(sizeof(struct node));
	newNode->value=item;
	newNode->next=p->next;
	p->next=newNode;
	list->size++;
	return 1;
}

int addListTail(List list, Item item){
	return addListPos(list,item,sizeList(list));
		
}

void mintotail(List *list)
{
    struct node *p, *prev;
    Item min;
    for(p=(*list)->head, min=(*list)->head; p!=NULL; prev=p, p=p->next)
    {
        if(cmpItem(min,p->value)>=1)
        {
            min=p->value;
        }
    }
    removeListItem((*list),min); 
    addListTail((*list),min);
}

List cloneList(List list){
	List clone=newList();
	struct node *p;
	for (p=list->head; p!=NULL; p=p->next){
		addListTail(clone,p->value);
	}
	return clone;
}






