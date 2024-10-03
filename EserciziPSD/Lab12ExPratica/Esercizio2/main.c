#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>

BTree newRandomTree(int maxh); 


char *OriginalRec(BTree tree,char *str){//nel caso delle stringhe e array non si utilizza & vengono già passate come puntatori

  if(!isEmptyTree(tree)){
	
	if(getLeft(tree) && getRight(tree)){
		printf("(");
		strcat(str,"(");
	}
	OriginalRec(getLeft(tree),str);

	outputItem(getBTreeRoot(tree));
	char *s=itemToString(getBTreeRoot(tree));//itemtostring restituisce un * quindi s non andava bene
	strcat(str,s);

    OriginalRec(getRight(tree),str);
	
	if(getLeft(tree) && getRight(tree)){
		printf(")");
		strcat(str,")");
	}
  }
  
}

char *Original(BTree tree){
	char *st=calloc(100,sizeof(char));
    OriginalRec(tree,st);
    return st;
}


int main(){
	srand(time(NULL)); // lasciare questa riga

	int n=4;
	//char str[100]="";
	BTree b=newRandomTree(n);
	printTree(b);
	//printf("\nModified string: %s\n", Original(b));
	Item i=inputItem();
	insertNode(b,i);
	printTree(b);
	Item s=inputItem();
	deletenode(b,s);
	printTree(b);
}

BTree newRandomTree(int maxh) {
	if(maxh <= 0)
		return NULL;
	BTree left = NULL, right = NULL;
	if(rand() % 3) {
		left = newRandomTree(maxh - 1);
		right = newRandomTree(maxh - 1);
	}
	char *a = calloc(2, sizeof(char));
	char ops[] = {'+', '-', '*', '/'};
	a[0] = left ? ops[rand() % 4] : '0' + rand() % 10;
	return buildTree(left, right, a);
}
