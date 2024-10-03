#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "libro.h"
#include <string.h>
#include "catalogo.h"


int main()
{
    int pos;
    char *name="ballin";
	catalogo cat=newcatalogo(name);
    libro l;

	for (int i=0; i<2; i++){
		l = inputItem();
		AddLibro(cat,l);
	}

    libro s=inputItem();
    search(cat,s,&pos);
    printf("posizione: %d", pos);
    printcatalogo(cat);

}
