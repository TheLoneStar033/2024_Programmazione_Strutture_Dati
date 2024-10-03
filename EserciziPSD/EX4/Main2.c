#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Functions.h"


int main() {
    // Definire il numero di punti e la distanza minima
    int n, d;
    printf("Inserisci il numero di punti: ");
    scanf("%d", &n);
    printf("Inserisci la distanza minima tra due punti: ");
    scanf("%d", &d);

    // Allocare memoria per i punti
    struct punto *punti = (struct punto *) malloc(n * sizeof(struct punto));

    // Richiedi all'utente l'input dei punti
    printf("Inserisci gli ascissi dei %d punti separati da spazi: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &punti[i].x, &punti[i].y);
    }

    // Calcolare il centroide
    struct punto *centroide = ottieni_centroide(punti, n);

    // Contare il numero di coppie di punti con distanza minore di d
    int count = conta_coppe_distanti(punti, n, d);

    // Stampa il risultato
    printf("Il numero di coppie di punti con distanza minore di %d e': %d\n", d, count);

    // Calcola la distanza massima tra le coppie di punti
    double distanzaMassima = calcola_distanza_massima(punti, n);

    // Stampa il risultato
    printf("La distanza massima tra le coppie di punti e': %f\n", distanzaMassima);

    return 0;
}