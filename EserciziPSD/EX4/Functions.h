#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto {
    int x;
    int y;
};

struct punto *crea_punto(int x, int y);
void stampa_punto(struct punto *p);
int ascissa(struct punto *p);
int ordinata(struct punto *p);
void sposta_punto(struct punto *p, int deltaX, int deltaY);
double distanza(struct punto *p1, struct punto *p2);
struct punto *ottieni_centroide(struct punto *punti, int n);
int conta_coppe_distanti(struct punto *punti, int n, int d);
double calcola_distanza_massima(struct punto *punti, int n);