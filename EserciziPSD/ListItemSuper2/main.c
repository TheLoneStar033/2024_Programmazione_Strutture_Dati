#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){

	Item item;
	int pos;
	List list=newList ();

	for (int i=0; i<5; i++){
		Item item = inputItem();
		addHead (list, item);
	}


	printList (list);
	printf("inserisci l'item da cercare: \n");
	item = inputItem();
	searchListItem(list, item, &pos);
	printf("posizione: %d", pos);


/*
	printList (list);
	printf("\n");
	printf("inserisci l'item da eliminare: \n");
	item = inputItem();
	removeListItem(list, item);
	printList(list);
*/

/*
	printList (list);
	printf("\n");
	printf("inserisci la posizione dell'item da eliminare: \n");
	scanf("%d", &pos);
	removeListPos(list, pos);
	printList(list);
	return 0;
*/
	return 0;
}


