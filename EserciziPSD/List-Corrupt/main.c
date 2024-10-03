#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){

	int pos;
	List list=newList ();
	for (int i=0; i<5; i++){
		Item item = inputItem();
		addHead (list, item);
	}
	printList (list);
	
	/*printf("Inserisci la posizione dell'item da inserire : ");
	scanf("%d",&pos);
	printf("Inserisci l'item: ");
	Item item = inputItem();
	addListTail(list,item);*/
	sortList(list);
	printList(list);

    // print the sorted list
    //printList(list);

	/*List clone=cloneList(list);
	printf("\n");
	printList (clone);
	return 0;*/
}