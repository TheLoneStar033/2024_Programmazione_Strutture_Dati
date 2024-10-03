

#include <stdio.h>
#include "utils.h"
#include "item.h"
#define N 10
#define TRUE 1
#define FALSE 0

void inputArray(Item *a, int n){
	int i;
	for(i=0; i<n; i++){
		a[i] = inputItem();//c'era una scanf
	}
}

void outputArray(Item *a, int n){
	int i;
	for(i=0; i<n; i++){
		outputItem(a[i]);//c'era una printf
	}
	printf("\n");
}


void bubbleSort(Item *a, int n){ 
	for (int i=1;i<n;i++)
		for (int j=0;j<(n-i);j++)
			if (cmpItem(a[j], a[j+1])>0)//c'era a[j]>a[j+1]
				swap(&a[j],&a[j+1]);
}


