#include <stdio.h>
#include "btree.h"
#include "item.h"


int main(){
	/*
	BTree d,e,f,g,b,c,a;
	d=buildTree(NULL,NULL,"d");//Inizializzazione foglie (nodi/alberi senza puntatori ad alberi successivi)
	e=buildTree(NULL,NULL,"e");
	f=buildTree(NULL,NULL,"f");
	g=buildTree(NULL,NULL,"g");
	b=buildTree(d,e,"b");
	c=buildTree(f,g,"c");
	a=buildTree(b,c,"a");
	
	
	BTree s,j,k,l,m,q,y;
	s=buildTree(NULL,NULL,"d");//Inizializzazione foglie (nodi/alberi senza puntatori ad alberi successivi)
	j=buildTree(NULL,NULL,"e");
	k=buildTree(NULL,NULL,"f");
	l=buildTree(NULL,NULL,"g");
	m=buildTree(d,e,"b");
	q=buildTree(f,g,"c");
	y=buildTree(b,c,"a");
	*/

	BTree d,e,f,g,b,c,a;
	d=buildTree(NULL,NULL,"10");//Inizializzazione foglie (nodi/alberi senza puntatori ad alberi successivi)
	e=buildTree(NULL,NULL,"12");
	f=buildTree(NULL,NULL,"23");
	g=buildTree(NULL,NULL,"21");
	b=buildTree(d,e,"11");
	c=buildTree(f,g,"3");
	a=buildTree(b,c,"4");

	BTree s,j,k,l,m,q,y;
	s=buildTree(NULL,NULL,"10");//Inizializzazione foglie (nodi/alberi senza puntatori ad alberi successivi)
	j=buildTree(NULL,NULL,"12");
	k=buildTree(NULL,NULL,"23");
	l=buildTree(NULL,NULL,"21");
	m=buildTree(s,j,"11");
	q=buildTree(k,l,"3");
	y=buildTree(m,q,"4");
	
	//BTree x=newTree();
	//BTree z=newTree();
	int gs=uguali(y,a);
	printf("%d\n",gs);
    
	/*printf("Visita in pre ordine: " );
	preOrder(a);
	printf("\nVisita in post ordine: " );
	postOrder(a);
	printf("\nVisita simmetrica: " );
	inOrder(a);*/


	return 0;
}


