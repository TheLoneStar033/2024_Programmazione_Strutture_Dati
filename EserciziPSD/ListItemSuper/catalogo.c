#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "libro.h"
#include <string.h>
#include "catalogo.h"


struct catalogo{
    char *name;
    List libri;
};


catalogo newcatalogo(char *name)
{
    catalogo c=malloc(sizeof(struct catalogo));
    c->name=strdup(name);
    c->libri=newList();
    return c;
}

void AddLibro(catalogo c,libro l){
    addHead(c->libri,l);
}

void removelibro(catalogo c,char *title)
{
    libro l=InitLibro(title,"",0);
    removeListItem(c->libri,l);
}

void printcatalogo(catalogo c)
{   

    printList(c->libri);
}

libro search(catalogo c, libro l, int *pos)
{
    searchListItem(c->libri,l,pos);
}






