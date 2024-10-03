/*Scrivere un programma classifica che permetta di esaminare la classifica piloti
di un campionato di Formula 1 memorizzata in un file classifica.txt. Il programma pu`o
essere usato in due modi.
1) Prende da linea di comando il cognome di un pilota o un suo prefisso e stamper`a il nome
completo del pilota seguito dalla sua scuderia e dal suo numero di punti. 

Esempio:
> ./classifica Giovinazzi
Antonio Giovinazzi Alfa Romeo Racing Ferrari 14

2) Prende da linea di comando due interi a e b e stamper`a, il nome completo del pilota che
ha pi`u punti fra tutti quelli che ne hanno totalizzato un numero compreso tra a e b, seguito
dalla sigla della sua nazione e dal suo numero di punti. 

Esempio:
> ./a.out 100 300
Max Verstappen NED 278

Attenzione: Potrebbe essere utile la funzione int strncmp(const char *s1, const
char *s2, size_t n) che `e come la strcmp, ma fa il confronto soltanto dei
Il file classifica.txt ha il seguente formato. Si precisa che sia il nome sia il cognome
del pilota sono singole stringhe. Si noti che l’elenco non `e ordinato e che il numero di spazi
fra gli elementi `e indefinito
 primi (al pi`u)
n byte di s1 and s2.
Per la stampa dell’output, ci si attenga strettamente alle indicazioni date sopra e illustrate
nei seguenti esempi, evitando di introdurre frasi non richieste, come: ”I piloti della scuderia ...
sono ..., il pilota ... ha ... punti, ecc. Soluzioni che ignorino tali indicazioni, rischiano
di essere penalizzate o di non essere prese in considerazione!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME_FILE "classifica.txt"


int main(int argc, char *argv[])
{
  FILE *fp;
  if ( (fp=fopen(NOME_FILE,"r")) == NULL)
  {
  	fprintf(stderr,"Non posso aprire il file");
  	exit(EXIT_FAILURE);
  }

  //fprintf(stderr,"test"); debug
  if (argc<2)
  {
  	fprintf(stderr,"USO SBAGLIATO\n uso corretto: NOME_FILE.EXE/./A.OUT Nome_pilota oppure intervallopunti1 intervallo punti2");
  	exit(EXIT_FAILURE);
  }
  
  char line[256],nome[80],cognome[80],nazione[12],scuderia[128],MaxPoint[30];
  int n,punteggio,maxp=0;
  
  while(fgets(line, sizeof(line),fp))
  {
	//n=sscanf(line,"%[^0123456789],%[^0123456789],%[0123456789],%[^0123456789\n]",nome,nazione,&punteggio,scuderia);
    n=sscanf(line,"%s %s %s %d %[^0123456789\n]",nome,cognome,nazione,&punteggio,scuderia);
    //printf("\nnome:%s cognome:%s nazione:%s punteggio:%d scuderia:%s",nome,cognome,nazione,punteggio,scuderia);
	//strcat(nome,"\t");
    //strcat(nome,cognome);
    
    if(argv[2]){
    	
    	if (punteggio>=atof(argv[1])&& punteggio<=atof(argv[2]))
        if(punteggio>maxp){
    	maxp=punteggio;
    	sprintf(MaxPoint,"%s,%s,%s,%d",nome,cognome,nazione,punteggio);
    }
    	
	}
	
	if(strncmp(argv[1],cognome, strlen(argv[1]))==0)
	printf("\nnome:%s cognome:%s nazione:%s punteggio:%d scuderia:%s",nome,cognome,nazione,punteggio,scuderia);
		
}

if(argv[2]){
printf("%s",MaxPoint);
if(maxp==0)
printf("Nessun Pilota con un punteggio nell'intervallo'");
}
}

