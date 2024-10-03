#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "libro.h"

char titlein[20];
char authorin[20];
int yearin;

Item inputItem(){
printf("title:");
fflush(stdin);
scanf("%[^\n]",titlein);//%[^\n] per prendere stringa fino a nuova linea

printf("author:");
fflush(stdin);
scanf("%[^\n]",authorin);

printf("year:");
fflush(stdin);
scanf("%d",&yearin);

//Non usiamo * perchè gli array di caratteri vengono già passati come puntatori
return InitLibro(titlein,authorin,yearin);//dopo aver raccolto i valori li passiamo a initlibro che crerà il libro

}

void outputItem(Item item){
	libro l=item;
	printf("%s - %s - %d",title(l),author(l),year(l));
}

int cmpItem(Item item1, Item item2){
	libro l1=item1;
	libro l2=item2;
	return strcmp(title(l1),title(l2));
}