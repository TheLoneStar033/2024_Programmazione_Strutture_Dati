#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME_FILE "temp.txt"

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
  if (argc>2)
  {
  	fprintf(stderr,"Uso Sbagliato Utilizzo: NOME_ESEGUIBILE.exe Punti1 oppure Punti1 Punti2");
  	exit(EXIT_FAILURE);
  }
  
//VARIABILI
char line[100],citta[20],p[20];
int temp,tt=0;
int n,i;
  
  
while(fgets(line, sizeof(line),fp))
{
n=sscanf(line,"%s %d %[^\n]",citta,&temp,p);  

printf("%s %d %s",citta,temp,p);

while(p[i]!='\n',i++)
{
	if(p==",")
	tt=tt+25;
}
printf("%s %d %s %d",citta,temp,p,tt);
}
}
