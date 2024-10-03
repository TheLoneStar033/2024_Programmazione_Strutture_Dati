#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include <string.h>

void reversegreaterthan(Queue Q1, int n, int *c,int s){

	if(!isEmptyQueue(Q1)){
		Item item=dequeue(Q1);
		if(*c==n || *c>n){
			 s=1;
		}
		*c=*c+1;
		reversegreaterthan(Q1,  n,  c, s);
		if(s==1)
		{
			enqueue(Q1,item);
		}

	}
}

void reversebelowthan(Queue Q1,char *s){//con * passiamo una stringa di caratteri

	if(!isEmptyQueue(Q1)){
		Item item=dequeue(Q1);
		//---------------------- ITEM TO CHAR CONVERTER ---------------
		//printf("\n c: uguale a:%s",s);
		char *c;
		c=item;//c=(char *)item
		//printf(" %s ",c);//PER STAMPARE CARATTERE (si usa *), per la stringa (non si usa *)
		//-------------------------------------------------------------
		
		reversebelowthan(Q1,s);
		
		if(strcmp(c,s)==-1){
			enqueue(Q1,item);
		}
	}
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

	Queue que1;
	que1=newQueue();
	for(int i=0;i<5;i++){
		Item item=randomItem();
		enqueue(que1,item);
	}
	printQueue(que1);

	char *s;
	Item param=inputItem();
	s=(char *)param;

	printf("%s",s);

	reversebelowthan(que1,s); //passiamo la stringa(senza *)
	printQueue(que1);

	
	/*int n=1,c=0,s=0;
	reversegreaterthan(que1,  n,  &c, s);
	printQueue(que1);*/

	

}
