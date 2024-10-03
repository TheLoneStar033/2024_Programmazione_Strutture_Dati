#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"


//int isANumber(char c);

int max(int a, int b){
	if(a>b)
	return a;
	else
	return b;
}

int Altezza(BTree b)
{
	if(isEmptyTree(b))
	{
		return -1;
	}
	else if(!getLeft(b) && !getRight(b))
	return 0;

	return 1+max(Altezza(getRight(b)),Altezza(getLeft(b)));
}

void MaxPath(BTree b)
{

	if(isEmptyTree(b))
	{
		return;
	}
	//else if(!getLeft(b) && !getRight(b))
	//return;

	if(Altezza(getRight(b))>Altezza(getLeft(b)))
	{
		Item value=getBTreeRoot(b);
		outputItem(value);
		MaxPath(getRight(b));

	}
	else
	{
		Item value=getBTreeRoot(b);
		outputItem(value);
		MaxPath(getLeft(b));
	}


	
}

int *sumbylevel(BTree b){
	int *sum=calloc(Altezza(b)+1,sizeof(int));

	if(isEmptyTree(b))
		return 0;
	//Calloc inizializza a 0 e malloc no(malloc è più efficiente)
	//item value=getBtreeroot(b);
	//sum[0]+=*(int*)value) restituisce l'intero contenuto in item value; 
	//sum[0]=getBTreeRoot(b);

	
	
}

int main(){
	BTree b=newRandomTree(7);
	printTree(b);
	printf("\n%d\n",Altezza(b));

	MaxPath(b);

	
}
