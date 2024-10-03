#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "libro.h"

struct libro{
    char *title; 
    char *author;
    int year;
};

libro InitLibro(char *title,char *author, int year){
    libro l=malloc(sizeof(struct libro));
    l->title=strdup(title);
    l->author=strdup(author);
    l->year=year;
    return l;
}

char *title(libro l){//Obbiettivo ritornare il valore dell'titolo presente nel libro
    char *title=malloc(sizeof(char)*strlen(1+(l->title)));
    strcpy(title,l->title);
    return title;

}

char *author(libro l){//Obbiettivo ritornare il valore dell'autore presente nel libro

    char *author=malloc(sizeof(char)*strlen(1+(l->author)));
    //author è un puntatore ad un area di memoria tipo char della grandezza
    //del valore author dell'adt ma più uno

    strcpy(author,l->author);//copiamo in author(nell'area di memoria quindi) che abbiamo inizializzato il valore di l->author
    return author;

}

int year(libro l){ //Nel caso dell'int possiamo effettuare semplicemente un return 
    return l->year;
}

//per verificare la corretta compilazione di questo singolo file è sufficiente usare gcc -c [NOMEFILE].c