/*Esercizio 1 
Scrivere un programma frequenze che permetta di esaminare l’elenco delle frequenze radio delle stazioni FM ricevibili a Salerno. L’elenco `e memorizzato in un file frequenze.txt.
Il programma pu`o essere usato in due modi.

1) Prende in input da linea di comando il nome di una stazione (o un suo prefisso). Esaminando il file, stamper`a il nome completo della stazione indicata, seguito dalla sua frequenza.
Nel caso ci siano pi`u stazioni che corrispondano al prefisso indicato sulla linea di comando, il
programma li stamper`a tutti (vedi Esempio 2 e 3).

2) Prende in input da linea di comando una frequenza in MHz. Esaminando il file, stamper`a
la stazione radio pi`u vicina alla frequenza indicata. Nel caso ci siano due stazioni radio alla
stessa minima distanza dalla frequenza indicata, il programma stampa solo una delle due scelta
arbitrariamente.

Attenzione: 
potrebbe essere utile la funzione int strncmp(const char *s1, const
char *s2, size_t n) che `e come la strcmp, ma fa il confronto soltanto dei primi (al pi`u)
n byte di s1 and s2. Si ricorda, inoltre, che lo specificatore di formato %[^ set] consente di
far corrispondere ogni sequenza di caratteri non presente in set.
L’elenco delle stazioni `e memorizzato in un file frequenze.txt che ha il seguente formato
(il numero di spazi fra gli elementi `e indefinito).*/


#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define LLEN 128
#define RLEN 80

#define NOME_FILE "Radio.txt"

//-------------------------------------INPUT TYPE--------------------------------------
int input_type(char *s)
{
for(;*s;s++)//Senza Punto e virgola prima di *s qui causava sempre return 1
{
	if((*s < '0' || *s > '9') && *s!='.')
	return 1; //RETURN 1 se inseriamo il nome di una radio
}
return 2;
}

int main(int argc,char *argv[])
{
  // ------------------------ CONTROLLO -----------------------------------------------
  FILE *fp;
  if ( (fp=fopen(NOME_FILE,"r")) == NULL)
  {
  	fprintf(stderr,"Non posso aprire il file");
  	exit(EXIT_FAILURE);
  }
  //fprintf(stderr,"test"); debug
  if (argc!=2)
  {
  	fprintf(stderr,"Uso Sbagliato Utilizzo: NOME_ESEGUIBILE.exe Frequenza/Stazione");
  	exit(EXIT_FAILURE);
  }
  
//---------------------------VARIABILI MAIN---------------------------------------------
char line[LLEN+1], Radio[RLEN+1];
float Freq,gap;
int n;
float min_gap=1000.0;
char Radio_vicina[RLEN+1];

//----------------------------- LETTURA ------------------------------------------------
while (fgets (line, sizeof(line),fp))
{
	n=sscanf(line,"%[^0123456789] %f", Radio, &Freq);
	//printf("N uguale a:%d",n); debug
	//printf("Radio:%s Freq%.2f\n",Radio,Freq); Debug
	
	//---------------------- TROVA FREQUENZA DA RADIO ----------------------------
	if (strncmp(argv[1],Radio,strlen(argv[1]))==0)
	{
		printf("\nLa frequenza della radio:%s e' %.2f",argv[1],Freq);
	}
	//--------------- TROVA RADIO DA FREQUENZA O RADIO VICINA -------------------
	else{
		gap=(atof(argv[1])-Freq);
	    if(gap<0)gap=-gap;
	    if (gap<min_gap)
		{
		min_gap=gap;
		//strcpy(Radio_vicina,Radio); test
		//Freq_vicina=Freq; test
		sprintf(Radio_vicina,"%s,%.2f",Radio,Freq);
	    }
    }
	    //printf("\nGAP:%.2f",gap); debug
	//---------------------------------------------------------------------------
}

if (input_type(argv[1])==2){
printf("\nLa Radio pi� vicina alla frequenza: e' %s",Radio_vicina);
}
fclose(fp);
return 0;
}
