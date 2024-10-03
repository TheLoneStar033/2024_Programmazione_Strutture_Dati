#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"

int main(){
	
	int count=0;
	BTree b=newRandomTree(5);
	printTree(b);
	RightNodeOnly(b,&count);
	Item item=inputItem();
	deleteNode(&b,item);
	printTree(b);

}
