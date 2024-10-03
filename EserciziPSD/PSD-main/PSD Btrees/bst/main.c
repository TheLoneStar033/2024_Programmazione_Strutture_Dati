#include <stdio.h>
#include "bst.h"
#include "item.h"

int main(){

	int a[]={20,10,30,5,15,25,40,3,6,35};
	BST tree = newBST();
	int i;
	Item item;

	for(i = 0; i < 10;i++){
		insertBST(&tree,&a[i]);
	}

	printf("\nInserisci un item da eliminare: ");
	item = inputItem();

	deleteBST(&tree, item);
	printf("MINIMO: ");
	outputItem(min(tree));
	printf("\n");
	printf("MASSIMO: ");
	outputItem(max(tree));


	return 0;
}
