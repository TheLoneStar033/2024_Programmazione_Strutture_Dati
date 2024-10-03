#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.dat"


int example(int argc1, char *argv1[])
{

 FILE *fp; //dichiarazione del puntatore fp che contiene il puntatore al file aperto quando
	//viene inizializzato, se il file non viene trovato fp = NULL.
	
	if(argc1!=2)
	{
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}
    fp = fopen(argv1[1], "r"); // apre example.dat per leggere

    if (fp == NULL)
    {
        printf("Impossibile aprire il file %s\n", argv1[1]);
        exit(EXIT_FAILURE); //Una volta eseguito EXIT il programma si chiude completamente non solo la funzione.
    }
	
	printf("%s can be opened\n", argv1[1]);
	
    fclose(fp);
    
    return 0;
}

int writeread() 
//questa funzione scrive in modalità append nel file io.txt volendo possiamo anche far passare il file da tastiera
{
	
	printf("function writeread executed");
	
	FILE *fp;
	fp=fopen("io.txt","a");

	int i;
	for(i=0;i<10;i++)
	{
		fprintf(fp,"%d\n", i);
	}
	
	fclose(fp);
	
	return 0;
}


int main(int argc, char *argv[])
{
	/* *argv[1] è un carattere singolo,la funzione example si aspetta un puntatore a un array di caratteri (char **)----------.
    Per correggere il codice, passare argv come secondo argomento a example. In questo modo, argv sarà un puntatore a un array 
	di puntatori a caratteri, che è quello che example si aspetta come secondo argomento.-------------------------------------*/

	example(argc, argv); 
	writeread();
	
	return 0;
    
	/*
	char str[40];
	int n=scanf("%[^0123456789]",str);
	printf("n: %d\n", n);
	*/
}
   
