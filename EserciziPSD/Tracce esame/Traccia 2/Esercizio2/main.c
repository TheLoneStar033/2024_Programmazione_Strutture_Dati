#include <stdio.h>
#include "btree.h"
#include <stdlib.h>
#include <string.h>

int max(int x,int y){
	return x>y?x:y;
}

int height(BTree bt) {

	if(isEmptyTree(bt)) return 0;
	else if(isEmptyTree(getLeft(bt)) && isEmptyTree(getRight(bt))) return 0;
	return 1 + max(height(getLeft(bt)), height(getRight(bt)));
	
}



int sumByLevel(BTree bt,int *a,int i){
	
	if(!isEmptyTree(bt)){

		//a[*i]=1;
		//printf("%d\n",a[0]);

		int *s=getBTreeRoot(bt);
		printf("root:%d\n",*s);

		printf("i:%d\n",i);
		a[i]+=*s;
		printf("i could be sex:%d\n",a[i]);

		sumByLevel(getLeft(bt),a,i+1);
		sumByLevel(getRight(bt),a,i+1);
		}

		else
		return 0;
	}

	int* sumByLevel2(BTree bt) {
	int h=height(bt);
	printf("h:%d\n",h);
	int *a=calloc(h+1,sizeof(int));
	sumByLevel( bt, a, 0);
	return a;
	}

void printHeightAndSumByLevel(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int h = height(bt);
	printf("Altezza albero: %d\n", h);
	printf("Somma nodi per ogni livello: ");
	int* sums = sumByLevel2(bt);

	for(int i = 0; i <= h; i++) {
		printf("%d ", sums[i]);
	}
	printf("\n\n");
}

int main(){
	// da scrivere
	BTree bt=newTree();
	bt=newRandomTree(4);
	printTree(bt);
	printHeightAndSumByLevel(bt);

	
	
}

