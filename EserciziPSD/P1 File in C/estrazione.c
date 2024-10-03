/*
Due parole x e y formano una estrazione z, se z `e la parola (di almeno un carattere)
che si ottiene unendo i caratteri che restano da x e y dopo aver scartato il prefisso e il suffisso
comuni di x e y, a patto che il prefisso comune abbia almeno una lettera e il suffisso comune
non sia pi`u corto del prefisso comune.

Ad esempio, atollo e appello formano l’estrazione toppe (il prefisso comune `e “a”, il suffisso
comune `e “llo”). 

Analogamente, pareggio e passaggio formano l’estrazione ressa. 

Invece, strabere e stranire non formano alcuna estrazione perch´e il suffisso comune “re”, in questo caso, `e pi`u
corto del prefisso comune “stra”. 

Inoltre, se x `e un prefisso di y, allora x e y non formano alcuna
estrazione perch´e z sarebbe vuota in tal caso.

Si scriva una funzione int estrazione(char *s, char *t, char *z) che nel caso in cui s e t 
formino una estrazione, restituisca 1 e memorizzi in z l’estrazione;

se, invece,
s e t non formano un’estrazione restituisca 0. 

Si usi la funzione in un programma che prenda
due stringhe s e t dalla riga di comando e stampi l’estrazione se essa esiste.
*/



#include <stdio.h>
#include <stdlib.h>
/*
void estrazione(char *s, char *t, char *z){
char *pt = t, *ps = s;
for(; *s == *t && *s; s++, t++)
;
if(*s == '\0' || *t == '\0')
return;
ps = s;
pt = t;
for (; *s; s++)
;
for (; *t; t++)
;
for (;*(s-1) == *(t-1); s--, t--)
;
*t = '\0';
while (ps < s)
*z++ = *ps++;
while (*z++ = *pt++)
;
}
*/

int estrazione(char *s, char *t, char *z) 
{
	char *ps=s,*pt=t;
	for(;*s==*t;s++,t++);
	printf("s:%c",*s);
	//printf("t:%c",*t);
	
	if (*s=='\0') 
	{
		printf("la stringa s è il prefisso della stringa t %c",*s);
		return 0;
	    
	}
	
	ps=s;
	pt=t;
	
    for (;*s; s++)
    ;
    for (; *t; t++)
    ;
    for (;*(s-1) == *(t-1); s--, t--){
      //printf("s:%c",*s);
      //printf("t:%c",*t);
     }

*t = '\0';
while (ps < s)
*z++ = *ps++;
while (*z++ = *pt++)
;

	//dubbio su comparazioni di grandezza puntatori <>=	
	//while(ps<s)
	//*z++=*ps++;
	//while(pt<t)
	//*z++=*pt++;
	
	//printf("s:%c",*s);
    //printf("t:%c",*t);
      
}

int main(int argc,char *argv[])
{
	
	char estratta[20];
	estrazione(argv[1],argv[2],estratta);
	printf("Z:%s",estratta);
	
}
