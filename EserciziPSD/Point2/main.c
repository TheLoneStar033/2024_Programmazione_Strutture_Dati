#include <stdio.h>
#include "point.h"

int main(){
    float x,y;
    printf("Inserisci le cordinate del primo punto :\n");
    scanf("%f%f", &x, &y);
    Punto p1=creaPunto(x,y); 
    /* il puntatore P1 punta alla locazione di memoria del puntatore p restituito dalla funzione creapunto 
    a cui sono stati passati i valori x,y da tastiera che quindi ha creato un puntatore a una struttura di tipo punto
    a cui sono stati assegnati quei valori, (possiamo estrarli uno per uno)*/

    /*Per semplicità possiamo dire di aver creato una nuovo tipo di dato come int float, ecc. che abbiamo chiamato Punto
    con Punto p1 dichiariamo una variabile p1 che consisterrà dei campi contenuti in punto*/

    printf("Inserisci le cordinate del secondo punto :\n");
    scanf("%f%f", &x, &y);
    Punto p2=creaPunto(x,y);

    printf("La distanza e': %.1f", distanza(p1,p2));

    return 0;
}
