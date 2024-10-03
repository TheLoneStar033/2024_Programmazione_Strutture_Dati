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

int* concatena_vet(int* a, int s, int* b, int m) {
    int* c = (int*) malloc((s + m) * sizeof(int));
    //Moltiplica la dimensione dell'intero 4 bytes per la variabile a cui s+m sta puntando ora
    int i;
    for (i = 0; i < s; i++) {//scorre e assegna i valori del primo array
        c[i] = a[i];
    }
    for (i = 0; i < m; i++) {//scorre e assegna i valori del secondo array
        c[s + i] = b[i];
    }
    return c;
}

int *input_array_dyn(int *n, char *line)
{
    //Moltiplica la dimensione dell'intero 4 bytes per la variabile a cui n sta puntando ora
    int *array = (int *)malloc(sizeof(int) * (*n)); // * prima di (*n) è un moltiplica non uno star/pointer
    //(int *n) ci permette di passare il valore di n alla funzione malloc, effettua un casting da puntatore a puntatore di intero

    int i = 0, num;
    while (sscanf(line, "%d", &num) == 1) {
        array[i] = num;
        i++;
        while (*line!= ' ' && *line!= '\0')//verifica se effettivamente ci sono valori continui 
            line++;
        if (*line == ' ')//se il while è concluso probabilmente vi è uno spazio o un carattere non numerico 
        //ci spostiamo dopo per prendere il prossimo valore/numero
            line++;
    }
    *n = i;
    return array;
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
    
    for (int i=0; i < *inmax1; i++)a = a+array1[i];//forse potevo farlo diversamento
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
