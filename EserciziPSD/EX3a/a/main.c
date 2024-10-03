#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"
#include "utils.h"


int main()
{

    //DYNAMIC ARRAY ALLOCATION DICHIARAZIONI --------------------------------
    int n;
    char line[100];
    int *a,*b;
    //int *c;

    //PRIMO ARRAY DINAMICO
    printf("inserisci il vettore");
    scanf("%[^\n]",line);
    
    a = input_array_dyn(&n,line);
    bubbleSort(a,n);
    outputArray(a,n);

    //SECONDO ARRAY DINAMICO
    printf("inserisci il vettore");
    scanf("%[^\n]",line);
    
    b = input_array_dyn(&n,line);
    bubbleSort(b,n);
    outputArray(b,n);

    int s = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    
    int *c=concatena_vet(a, s, b, m);
    printf("Il vettore concatenato è: ");
    outputArray(c, s + m);
    free(c);

    return 0;
}

