#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definizione dell'ADT punto
struct punto {
    int x;
    int y;
};

// Funzione per creare un nuovo punto
struct punto *crea_punto(int x, int y) {
    struct punto *p = (struct punto *) malloc(sizeof(struct punto));
    p->x = x;
    p->y = y;
    return p;
}

// Funzione per stampare un punto
void stampa_punto(struct punto *p) {
    printf("(%d, %d)\n", p->x, p->y);
}

// Funzione per ottenere l'ascissa di un punto
int ascissa(struct punto *p) {
    return p->x;
}

// Funzione per ottenere l'ordinata di un punto
int ordinata(struct punto *p) {
    return p->y;
}

// Funzione per spostare un punto in base a x e y
void sposta_punto(struct punto *p, int deltaX, int deltaY) {
    p->x += deltaX;
    p->y += deltaY;
}

// Funzione per ottenere la distanza tra due punti
double distanza(struct punto *p1, struct punto *p2) {
    int xDiff = ascissa(p1) - ascissa(p2);
    int yDiff = ordinata(p1) - ordinata(p2);
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Funzione per ottenere il centroide di un insieme di punti
struct punto *ottieni_centroide(struct punto *punti, int n) {
    struct punto *centroide = (struct punto *) malloc(sizeof(struct punto));
    int sommaX = 0, sommaY = 0;

    for (int i = 0; i < n; i++) {
        sommaX += punti[i].x;
        sommaY += punti[i].y;
    }

    centroide->x = sommaX / n;
    centroide->y = sommaY / n;

    return centroide;
}


// Funzione per calcolare il numero di coppie di punti con distanza minore di d
int conta_coppe_distanti(struct punto *punti, int n, int d) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distanza(punti + i, punti + j) < d) {
                count++;
            }
        }
    }
    return count;
}

// Funzione per calcolare la distanza massima tra le coppie di punti
double calcola_distanza_massima(struct punto *punti, int n) {
    double maxDistanza = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distanza = distanza(punti + i, punti + j);
            if (distanza > maxDistanza) {
                maxDistanza = distanza;
            }
        }
    }
    return maxDistanza;
}

