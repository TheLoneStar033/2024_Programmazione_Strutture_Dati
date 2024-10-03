/* Si scriva una funzione void substitute (char *s1, char *s2, int m)
che prenda in input una stringa s1, una stringa s2 e un intero m e modifichi (sul posto, cio`e
senza l'ausilio di stringhe di appoggio) la stringa s1 nel seguente modo.

La parte di s1 compresa tra il suo carattere m-esimo e il carattere (m+l)-esimo (dove `l`e la
lunghezza di s2) viene sostituita con s2. Se la stringa s2 `e troppo lunga per essere compresa
entro la lunghezza di s1, allora s1 viene lasciata invariata. Esempi:

>./a.out buonocorno gi 5
buongiorno
>./a.out buongiorno aserata 5
buongiorno

Si scriva la funzione in un programma che prenda i tre parametri s1, s2 e m dalla linea di
comando e stampi la stringa s1 modificata.
Attenzione: Il programma pu`o usare solo le librerie <stdio.h> e <stdlib.h>. */


#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str)
{

int len;

for(len=0;str[len]!=0;len++)
{
}
//printf("len:%d",len);
return len;

}

void substitute (char *s1,char *s2, int m)
{
	printf("s1:%s, s2:%s, m:%d",s1,s2,m);
	
	char *sstart=s1;
	s1=s1+(m-1);//mi posiziono dove iniziare a scrivere la stringa successiva
	
	//char *p=s2;
	
	//while(*s1 && m--)
	//s1++;
	if(my_strlen(s1)+my_strlen(s2)<=my_strlen(sstart)+2){
    //rintf("len1mod:%dlen2:%dlen1nonmod:%d",my_strlen(s1),my_strlen(s2),my_strlen(sstart));
	while(*s1&&*s2)
	{
	printf("len1mod:%dlen2:%dlen1nonmod:%d",my_strlen(s1),my_strlen(s2),my_strlen(sstart));
	printf("\ns1:%c",*s1);
	*s1=*s2;
	s1++;
	s2++;
    }
}
 else return;
    //printf("s1:%s",s1-p);
    
    if(*s1=='\0'&& *s2=='\0') return;
    s1--;
    s2--;
    
    
    //for(;s2>=p;s1--,s2--)
	//{
		//printf("s1:%c",*s1);
    	//*s1=*s2;
	//}
	
		//printf("s1:%c",*s1);
    
    
	
	
	
}

int main(int argc,char *argv[])
{
	if(argc!=4)
	{
		printf("utilizzo sbagliato, utilizzo corretto: FRASE1 FRASE2 INTERO1");
	}
	
	int numb=atoi(argv[3]); // Converte la stringa in un intero
	
	substitute(argv[1],argv[2],numb);
	//my_strlen(argv[1]);
	printf("\nStringa Finale:%s",argv[1]);
}
