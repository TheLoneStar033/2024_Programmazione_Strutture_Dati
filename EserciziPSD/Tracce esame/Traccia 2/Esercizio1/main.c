#include <stdio.h>
#define N 30
#include <string.h>
#include <stdlib.h>
#include "list.h"


void reverseList(List list,Item item1){
    if(!isEmpty(list))
	{
		Item item1=getHead(list);
		removeHead(list);
	
	reverseList(list,item1);


	addListTail(list,item1);
	}
}

void Filter(List list,Item item1,char *cs){
    if(!isEmpty(list))
	{
		Item item1=getHead(list);
		removeHead(list);

		char *s=(char *)item1;
		//printf("%s: ",s);
		//printf("%s",cs);
	
	Filter(list,item1,cs);
	
	if(s[0]!=cs[0])
	addHead(list,item1);

	}
}

void reverser(List list)
{
	Item item=calloc(1,sizeof(Item));
	reverseList(list,item);
}


int main() {

	List list=newList();
	addHead(list,"allah");
	addHead(list,"amogus");
	addHead(list,"nigas");
	addHead(list,"sex");
	printList(list);
	char *cs="a";
	Item item1;
	Filter(list,item1,cs);
	printList(list);






	/*--------------------------------------------------------------
	char exp1[N]="(1+[x+{5+4}-7])";
	char exp2[N]="(1+2";
	char exp3[N]="(2+[3*4+{5])";
	char exp4[N]="";
	char exp5[N]="[";

	printf("1) Valuto: %s\n", exp1);
	if (isBalanced(exp1))
		printf("L' espressione e' bilanciata\n\n");
	else
		printf("L'espressione non e' bilanciata\n\n");

	printf("2) Valuto: %s\n", exp2);
	if (isBalanced(exp2))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("3) Valuto: %s\n", exp3);
	if (isBalanced(exp3))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("4) Valuto: %s\n", exp4);
	if (isBalanced(exp4))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("5) Valuto: %s\n", exp5);
	if (isBalanced(exp5))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");
}
-----------------------------------------------------------------*/

}