void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *a, int n) {
	for (int i=1;i<n;i++)
		for (int j=0;j<(n-i);j++)
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}