#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "libro.h"

typedef struct catalogo *catalogo;

catalogo newcatalogo(char*);
void AddLibro(catalogo ,libro );
void removelibro(catalogo,char *);
void printcatalogo(catalogo );
libro search(catalogo , libro , int *);

