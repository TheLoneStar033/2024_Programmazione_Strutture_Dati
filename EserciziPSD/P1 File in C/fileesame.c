/*
Si scriva un programma chiamato cannonieri che consenta di esaminare una
classifica cannonieri della Serie A memorizzata in un file cannonieri.txt.
Ogni riga presenta, nell’ordine indicato, i seguenti elementi separati da uno o pi`u spazi: numero_di_reti, nome, cognome, numero_di_reti_su_rigore, squadra.
Ogni elemento `e composto da una sola parola. Il file non `e ordinato in base al numero di reti
segnate dai calciatori. Ad esempio:

8 Angelo Domenghini 0 Cagliari
8 Gianni Rivera 3 Milan
21 Gigi Riva 4 Cagliari
12 Luciano Chiarugi 0 Fiorentina
12 Giorgio Chinaglia 2 Lazio
8 Sergio Clerici 0 Verona
7 Lucio Mujesan 0 Bologna
17 Alessandro Vitali 6 Vicenza
15 Pietro Anastasi 2 Juventus
13 Roberto Boninsegna 2 Inter
12 Pierino Prati 2 Milan
9 Mario Bertini 6 Inter
8 Jose Altafini 1 Napoli

Il programma pu`o essere utilizzato in tre modi:

A. Senza parametri: il programma stampa il nome del capocannoniere seguito dal numero
di reti segnate
> ./cannonieri
Gigi Riva 21
2

B. Passando il nome del programma seguito da un numero intero x: il programma stampa su
righe separate il nome e cognome dei calciatori che hanno totalizzato esattamente x reti,
indicando tra parentesi la squadra di appartenenza seguita dal numero di reti su rigore.

> ./cannonieri 12
Luciano Chiarugi (Fiorentina) 0
Giorgio Chinaglia (Lazio) 2
Pierino Prati (Milan) 2

C. Passando il nome del programma seguito dal nome di una squadra (nome intero e non
un suo prefisso): il programma stampa il nome e cognome del miglior marcatore di quella
squadra, seguito dal numero di reti segnate.

> ./cannonieri Milan
Pierino Prati 12

Ogni situazione non specificata nei tre punti precedenti (inclusi vari casi di input non validi)
pu`o essere ignorata o gestita liberamente.

Attenzione:
• Si pu`o assumere che il formato del file cannonieri.txt sia sempre corretto.
• Per la stampa dell’output, attenersi alle indicazioni date sopra e illustrate negli esempi,
evitando di introdurre frasi non richieste.
Esempio di output con input errato:

> ./cannonieri Milan Inter
Uso: ./cannonieri
Uso: ./cannonieri <intero>
Uso: ./cannonieri <squadra>
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME_FILE "cannonieri.txt"

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
  if (argc<0||argc>2)
  {
  	fprintf(stderr,"");
  	exit(EXIT_FAILURE);
  }
  
//INPUT TYPE
int inputype=1;

if(argc==1)
inputype=0;
  
//VARIABILI
int num_reti,num_retirig;
char line[128],nome[20],cognome[20],squadra[20];
printf("inputtype %d",inputype);

//input type 0
int max=0,min=999;
char bomber[30];
 
while(fgets(line,sizeof(line),fp))
{
  sscanf(line,"%d %s %s %d %[^'\n']",&num_reti,nome,cognome,&num_retirig,squadra);
  printf("\n%d,%s %s,%d,%s",num_reti,nome,cognome,num_retirig,squadra);	
  
  if(inputype==0)
  {
  	if(num_reti>max)
  {
	  
  	max=num_reti;
  	sprintf(bomber,"%s %s %d", nome, cognome,num_reti);
  }

  }
 
}

if(inputype==0)
  {
    printf("%s",bomber);
}

}






