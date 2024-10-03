#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Functions.h"

int main() {
    // Richiedi all'utente l'input dei due punti
    struct punto punti[2];
    printf("Inserisci l'ascissa del primo punto: ");
    scanf("%d", &punti[0].x);
    printf("Inserisci l'ordinata del primo punto: ");
    scanf("%d", &punti[0].y);
    printf("Inserisci l'ascissa del secondo punto: ");
    scanf("%d", &punti[1].x);
    printf("Inserisci l'ordinata del secondo punto: ");
    scanf("%d", &punti[1].y);

    // Stampa dei punti
    stampa_punto(&punti[0]);
    stampa_punto(&punti[1]);

    // Spostamento del primo punto di 10 unità in alto e 5 unità a destra
    sposta_punto(&punti[0], 10, 5);

    // Stampa del primo punto spostato
    printf("Primo Punto spostato:\n");
    stampa_punto(&punti[0]);

    // Calcolo del centroide dei punti
    struct punto *centroide = ottieni_centroide(punti, 2);

    // Stampa del centroide
    printf("Il centroide dei punti e': \n");
    stampa_punto(centroide);

    return 0;
}