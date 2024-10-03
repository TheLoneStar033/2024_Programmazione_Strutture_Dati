/*Scrivere un programma campionato che permetta di esaminare la classifica di serie A del campionato di calcio 1969-1970. La classifica `e memorizzata in un file classifica.txt.
Ogni linea del file corrisponde ad una squadra e presenta, in ordine, i seguenti elementi: il nome
della squadra, il numero di vittorie, il numero di pareggi, il numero di sconfitte, il numero di
gol fatti, il numero di gol subiti. 

Il programma pu`o essere usato in tre modi.

1) Prende in input da linea di comando un intero x. Stampa le squadre che hanno almeno x
punti. Ogni squadra `e seguita dal suo numero di punti. Una vittoria vale 2 punti e un pareggio
1 punto (Esempio 1).

2) Prende in input da linea di comando il carattere v seguito da un intero x. Stampa la
squadra che ha fatto pi`u gol fra quelle che hanno realizzato al massimo x vittorie. La squadra
`e seguita dal suo numero di vittorie e dal suo numero di gol fatti (Esempio 2).

3) Prende in input da linea di comando due interi x e y. Stampa la squadra che ha realizzato
pi`u gol e la squadra che ha realizzato meno gol fra tutte quelle che hanno un numero di punti
compreso fra x e y, estremi inclusi. La squadra `e seguita dal suo numero di gol fatti (Esempio
3).

Il file classifica.txt ha il seguente formato (il numero di spazi fra gli elementi `e
indefinito).

Bologna 6 16 8 22 24
Roma 8 12 10 27 36
Verona 8 10 12 26 30
Bari 5 9 16 11 35

Esempio 1.
> ./campionato 40
Cagliari 45
Inter 41

Esempio 2.
> ./campionato v 14
Milan 13 38
2

Esempio 3.
> ./campionato 30 35
Napoli 24
Torino 20
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME_FILE "calcio.txt"

int input_type(char *s,char *t) // ATTENZIONE qui non potevo utilizzare if(*t) perchè il valore *t nel caso non esistesse non veniva proprio passato
//ed il programma crashava.
{
	if(*s=='v')
	return 1;
	
	if(*s)
	return 2;

}


char Esempio3(int s,int t,int numpunt,int golfat,char *mins,char *maxs,char *nomesq,int min,int max)//se passo il valore char convertito in int con atof non devo usare puntatore ATTENZIONE
{//se passo una stringa invece uso *

	//printf("%d %d",s,t);
	printf("\n%d\n",numpunt);
	if(numpunt>=s && numpunt<=t)
	{
		printf("max %d",max);
		printf("golfat:%d",golfat);
		if(golfat>max)
		{
		max=golfat;
		sprintf(maxs,"%s %d",nomesq,max);
		//printf("\nmaxs:%c",maxs);
	    }
	    //printf("max:%d",max);

	    
		//if(golfat<=min) 
		//{
		//min=golfat;
		//printf("mins:%d",min);
		//sprintf(mins,"%s %d",nomesq,min);
		//printf("\nmins:%c",mins);
	    //}
	}
}

int main(int argc,char *argv[])
{
// ------------------------ CONTROLLO --------------------------------------------------
  FILE *fp;
  if ( (fp=fopen(NOME_FILE,"r")) == NULL)
  {
  	fprintf(stderr,"Non posso aprire il file");
  	exit(EXIT_FAILURE);
  }
  //fprintf(stderr,"test"); debug
  if (argc<2)
  {
  	fprintf(stderr,"Uso Sbagliato Utilizzo: NOME_ESEGUIBILE.exe Punti1 oppure Punti1 Punti2");
  	exit(EXIT_FAILURE);
  }
  
//---------------------------VARIABILI MAIN---------------------------------------------
char line[100],nomesq[20],maxxer[20];
int numvit,numpar,numsconf,golfat,golsub;
int n,numpunt,maxgol=0;
char mins[30],maxs[30];
//int min=1000,max=0;

while(fgets(line, sizeof(line),fp))
{
n=sscanf(line,"%[^0123456789] %d %d %d %d %d",nomesq,&numvit,&numpar,&numsconf,&golfat,&golsub);
//printf("%s %d %d %d %d %d\n",nomesq,numvit,numpar,numsconf,golfat,golsub);
numpunt=((numvit*2)+numpar);
printf("%s NUMPUNT%d ",nomesq,numpunt);

//ESEMPIO 2 
if(input_type(argv[1],argv[2])==1)
{
	if(numvit<=atof(argv[2]))
	{
		if(golfat>maxgol){
		maxgol=golfat;
		sprintf(maxxer,"%s %d %d",nomesq,numvit,maxgol);
	}
		
	}
}
//Se avessi utilizzato else in questa posizione avrei causato un crash ATTENZIONE
if(input_type(argv[1],argv[2])==2){
	
	//ESEMPIO 3
	if(argv[2])
	{
		
		Esempio3(atof(argv[1]),atof(argv[2]),numpunt,golfat,mins,maxs,nomesq,min,max);
	}
	else //ESEMPIO 1
        if(numpunt>=atof(argv[1]))
        printf("\n %s %d",nomesq,numpunt);
}

}


//STAMPA ESEMPIO 2
printf("max:%s",maxs);
if(maxgol!=0)
printf("%s",maxxer);
}
