#include <stdlib.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
};

//Struttura autoreferziale
struct node {
    Item value; //data stored in the node
    struct node *next; //pointer to the next node also contains a value and a next pointer
};


List newList(){
    List list=malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    
    return list;
}

int isEmpty(List list){
    return list->size==0; //se size == 0 allora return true altrimenti return false
}

void addHead(List list, Item item){
    struct node *newNode= malloc(sizeof(struct node)); //Puntatore temporaneo che punta al nodo + memoria indirizzo
    newNode->value = item; //assegna il valore di item (passato da tastiera) a value in newnode
    newNode->next = list->head; //il campo next punta alla testa della lista (Null la prima volta)
    list->head = newNode; //(il nuovo nodo diventa la testa della lista)
    list->size++; //Aumenta il contatore della dimensione della lista
}

Item removeHead(List list){
    if (isEmpty (list)) return NULL;
    struct node *temp= list->head;
    list->head = temp->next;//Head assume il valore del nodo successivo alla vecchia head ossia il valore prima
    Item item = temp->value; //item assume il valore del nodo della vecchia head
    free (temp);
    list->size--;
    return item; //returns the value of the removed node
}

Item getHead(List list){ //getFirst
    if (isEmpty (list)) return NULL;
    return list->head->value;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head; p!=NULL; p=p->next)//for per scorrere la lista 
        outputItem(p->value);
}

Item searchListItem(List list, Item item, int *pos){
	struct node *p;
	*pos=0;
    for (p=list->head; p!=NULL; p=p->next){
       if (cmpItem(item,p->value)==0){
		   return p->value;
	   }
	   (*pos)++;
	}
	*pos=-1;
	return NULL;
}
Item removeListItem(List list, Item item){
	Item temp;
	if (isEmpty(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
       if (cmpItem(item,p->value)==0){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next; // Prev il nodo prima di P avrà come valore next il successivo a P ma il suo valore sarà sempre
			//quello del nodo prima di P.
			temp = p->value;
			free (p); //LIBERA LA MEMORIA A CUI STA PUNTANDO P quindi il valore della lista
			list->size--;
			return temp;
	   }
	
	}
	return NULL;
}

Item removeListPos(List list, int pos){
	Item temp;
	int cont=0;
	if (isEmpty(list) || pos<0 || pos>=sizeList(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
		if (pos==cont){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next;
			temp = p->value;
			free (p);
			list->size--;
			return temp;
			             
		}
		cont++;
	}
	return NULL;
	
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
	newNode->next=p->next;//il successivo del nuovo nodo diventa il successivo del nodo attuale
	p->next=newNode; //il successivo del nodo attuale diventa nuovo nodo
	list->size++;
	return 1;
}

int addListTail(List list, Item item){ //aggiunge alla fine
	return addListPos(list,item,sizeList(list));
		
}

void reverseList(List list){//DA MENTALIZZARE GRAFICAMENTE SPOSTANDO I NODI IN REVERSE
	struct node *p,*prev=NULL,*temp;
	for (p=list->head; p!=NULL; prev=p, p=temp){
		temp=p->next; 
		p->next=prev;
	}
	list->head=prev;//Prev nell'ultima iterazione diventerà la vecchia coda, quindi la nuova testa
	
}

List cloneList(List list){
	List clone=newList();
	struct node *p;
	for (p=list->head; p!=NULL; p=p->next){
		addListTail(clone,p->value);
	}
	return clone;
}


