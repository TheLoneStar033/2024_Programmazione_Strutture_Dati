#include <stdio.h>
#include "point.h"

int main(){
    float x,y;
    printf("Inserisci le cordinate del primo punto :\n");
    scanf("%f%f", &x, &y);
    Punto p1=creaPunto(x,y);

    printf("Inserisci le cordinate del secondo punto :\n");
    scanf("%f%f", &x, &y);
    Punto p2=creaPunto(x,y);

    printf("La distanza e': %.1f", distanza(p1,p2));

    return 0;
}
