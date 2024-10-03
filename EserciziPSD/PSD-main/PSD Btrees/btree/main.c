#include <stdio.h>
#include "btree.h"
#include "item.h"

int main(){
	BTree d,e,f,g,b,c,a;
	d=buildTree(NULL,NULL,"d");//Inizializzazione foglie (nodi/alberi senza puntatori ad alberi successivi)
	e=buildTree(NULL,NULL,"e");
	f=buildTree(NULL,NULL,"f");
	g=buildTree(NULL,NULL,"g");
	b=buildTree(d,e,"b");
	c=buildTree(f,g,"c");
	a=buildTree(b,c,"a");
	

	printf("Visita in pre ordine: " );
	preOrder(a);
	printf("\nVisita in post ordine: " );
	postOrder(a);
	printf("\nVisita simmetrica: " );
	inOrder(a);

	return 0;
}
