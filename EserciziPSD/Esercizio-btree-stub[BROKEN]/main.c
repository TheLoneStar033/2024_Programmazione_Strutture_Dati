#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"


int isANumber(char c);

void SommaAlbero(BTree tree, int *sum){

	if(isEmptyTree(tree)){
		return;
	}
	Item item=getBTreeRoot(tree);

	int *value = item; // Convert Item to int
    *sum += *value; //Sum diventa uguale a sum della chiamata precedente + il valore attuale del nodo
	SommaAlbero(getLeft(tree),sum); //Propagazione di Sum
	SommaAlbero(getRight(tree),sum);
}

/*void AddNode(BTree *tree, Item item)
{
	if (!getLeft(*tree) ||!getRight(*tree)) {
		BTree newNode = buildTree(NULL, NULL, item);

		if (!getLeft(*tree)) {
			*tree = buildTree(newNode, NULL, getBTreeRoot(*tree));
		} else {
			*tree = buildTree(NULL, newNode, getBTreeRoot(*tree));
		}
	}

	if (getLeft(*tree)) {
		//AddNode(&getLeft(*tree), item);
	}
}*/

int main(){
	int i5=5, i3=3, i7=7, i8=9;

	BTree rr=buildTree(NULL,NULL,&i3);
	BTree rl=buildTree(NULL,NULL,&i5);
	BTree r=buildTree(rl,rr,&i7);

	//AddNode(getRight(r),&i8);
	
	insertBST(&r,&i8);
	int sum=0;
	SommaAlbero(r,&sum);
	printf("%d",sum);

	int suml=0,sumr=0,diff=0;
    SommaAlbero(getLeft(r),&suml);
	SommaAlbero(getRight(r),&sumr);
	if(suml>sumr)//Sicuramente dobbiamo aggiungere il nodo sull'albero destro
	diff=suml-sumr;
	
	
	else //Sicuramente dobbiamo aggiungere il nodo sull'albero sinistro
	diff=sumr-suml;

	printf("%d",diff);
}


int isANumber(char c) {
	return (c == '1' || 
		c == '2' || 
		c == '3' || 
		c == '4' || 
		c == '5' || 
		c == '6' ||
		c == '7' ||
		c == '8' ||
		c == '9' ||
		c == '0' 		
		);


}



