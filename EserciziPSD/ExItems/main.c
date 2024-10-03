#include "array.h"
#include "item.h"

#define N 10

int main(){

	Item array[N];//c'era int array[N]
	int n = 5;
	int val;
	inputArray(array, n);
	bubbleSort(array,n);
	outputArray(array,n);

	return 0;
}