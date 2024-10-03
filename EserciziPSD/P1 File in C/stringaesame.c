/* Si scriva una funzione int scarto_doppio(char *s, char *t, char *z,
int i) che prenda tre stringhe s, t, z e un intero i, 0 < i < min(lunghezza(s), lunghezza(t)).
La funzione dovr`a estituire 1 se si verificano entrambe le seguenti condizioni:

A. Le ultime i lettere della stringa t coincidono con le prime i lettere della stringa s, ma in
ordine inverso.

B. La stringa z si ottiene unendo le rimanenti lettere di s e t, nell’ordine in cui compaiono
in ciascuna stringa.

Ad esempio, date le stringhe s = "defabc", t = "xyzfed", z = "abcxyz" e l’intero
i = 3, la funzione scarto_doppio(s, t, z, i) restituir`a 1, poich`e le ultime 3 lettere di
t (”fed”) coincidono con le prime 3 lettere di s lette al contrario (”fed”), e la stringa ottenuta
unendo le rimanenti lettere di s e t `e z (”abcxyz”).

Attenzione: Il programma dovr`a prendere s, t, z e i dalla linea di comando e utilizzare la
funzione per stabilire se si verifica la condizione specificata. E’ consentito l’uso della funzione
int atoi(const char *nptr) (libreria <stdlib.h>). Il programma pu`o utilizzare solo
le librerie <stdio.h> e <stdlib.h>. */

#include <stdio.h>
#include <stdlib.h>

int scarto_doppio(char *s,char *t,char *z,int i)
{
	printf("s:%s, t:%s, z:%s i:%d",s,t,z,i);
	
	char *ps=s, *pt=t, *pz=z;
	int n=0;
	int c=0;
	
	for(;*t;t++);
	printf("\ns:%s, t:%s, z:%s i:%d",s,t,z,i);
	
	t=(t-1);
	
	printf("\ns:%s, t:%s, z:%s i:%d",s,t,z,i);
	
	for(;n<i&&*t==*s;)
	{
	t--;
	s++;
	n++;
    }
    
    if(n!=i)
    {
    	return 0;
	}
	
	printf("\ns:%s, t:%s, z:%s i:%d",s,t,z,i);
	
	for(;*s&&*s==*z;*s++,*z++)
	{
		c++;
	}
	printf("\nc:%d",c);
	
	//for(;*t;t--);
	//t=(t+1);
	printf("\ns:%s, pt:%c, z:%s i:%d",s,*pt,z,i);
	
	for(;*z&&*pt==*z;pt++,z++)
	{
		c++;
	}
	printf("\nc:%d",c);
	printf("\ns:%s, pt:%s, z:%s i:%d",s,pt,z,i);
	
	if(*z)
	{
		return 0;
	}
	else return 1;
	
}


int main(int argc,char *argv[])
{
	if(argc!=5)
	{
		printf("formato: stringa1 stringa2 stringa3 intero");
	}
	
	printf("r:%d",scarto_doppio(argv[1],argv[2],argv[3],atoi(argv[4])));
	
}
