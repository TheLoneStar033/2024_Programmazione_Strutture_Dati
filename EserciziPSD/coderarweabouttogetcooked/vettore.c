#include <stdio.h>
#include <stdlib.h>


int inputArray(int *array, char *line, int *pos)
{
    int i=0,n=0;
    
    while(sscanf(line,"%d %n",&array[i],&n)==1)
	{
        printf("n: %d\n caratteri: %d\n", array[i], n);
        
    line+=n;
    i++;
    
    }
return i;
}


int somma_array(int a[], int n)
{
    int i=0,somma=0; 
    
    for(;i<n;i++)
	{
        somma+=a[i];
    }

return somma;

}

void somma2_array(int *array1, int *array2, int *inmax1, int *inmax2)
{
    
    if(*inmax1<*inmax2) *inmax1=*inmax2;

    for (int i=0; (i<*inmax1); i++)
	{
        array1[i]=array1[i]+array2[i];
    }
}

int somma_prod(int *array1, int *array2, int *inmax1, int *inmax2)
{
    int a=0;
    
    if(*inmax1<*inmax2) *inmax1=*inmax2;
    for (int i=0; (i<*inmax1); i++)
	{
        array1[i]=array1[i]*array2[i];
    }
    
    for (i=0; i < *inmax1; i++)a = a+array1[i];//forse potevo farlo diversamento
    return a;
}


int Contr_OracleArray(int *array, int *oracle, int inmax)
{
    for(int i=0; i<inmax; i++)
	{
        if(array[i] != oracle[i])
        return 0; 
        
    return 1;    
    }
}

int gg_result(char *line)
{
    int n;
    
    sscanf(line,"%d",&n);
    return n;
}


void outputArray(int *a, int n) 
{
    for (int i=0;i<n;i++) 
	printf(" %d  ",a[i]);
}
