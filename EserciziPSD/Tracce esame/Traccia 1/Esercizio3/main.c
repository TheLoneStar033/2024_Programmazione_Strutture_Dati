#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"


Stack ReverseGreatherThan(Stack *s,Stack *s2,int n,int *c)
{
	if(!isEmptyStack(*s)){
		Item item=top(*s);
		pop(*s);
		if(*c==n || *c>n)
		{
			push(*s2,item);
		}
		*c=*c+1;
		ReverseGreatherThan(s, s2, n, c);
		push(*s,item);
}
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

	
	Stack stack=newStack();
	push(stack,"d");
	push(stack,"c");
	push(stack,"b");
	push(stack,"a");
	Stack stack2=newStack();
	int n=2;
	int c=0;
	ReverseGreatherThan(&stack, &stack2, n, &c);
	printStack(stack2);
	printStack(stack);





}
