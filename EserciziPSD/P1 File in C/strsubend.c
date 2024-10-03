/* Si scriva la funzione int strsubend (char *s, char *t, char *r) che
prenda in input tre stringhe, s, t e r, e si comporti come segue:

• se (a) la stringa t corrisponde alla parte finale di s (come ad esempio giorno in
buongiorno) e (b) le stringhe t e r hanno la stessa lunghezza, allora la funzione
restituisce 1 e sostituisce la parte finale di s (che corrisponde a t) con la stringa r;

• se una delle due condizioni (a) o (b) non `e verificata, la funzione lascia inalterata la stringa
s e restituisce 0.

Ad esempio supponiamo che s, t e r contengano le stringhe buongiorno, giorno e
anotte rispettivamente. In tal caso il seguente codice stamper`a buonanotte:

i f ( s t r s u b e n d ( s , t , r ) )
p r i n t f ( ”%s \n ” , s ) ;

Si noti che anche nel caso s = buongiorno, t = buongiorno e r = buonanotte, il
codice su indicato stamper`a buonanotte.

Attenzione: il programma dovr`a prendere le tre stringhe dalla linea di comando e pu`o
usare solo la libreria <stdio.h>.*/

#include <stdio.h>

int strsubend(char *s, char *t, char *r) {
    char *ps = s, *pt = t,z[100];
    int nt = 0, nr = 0;

    while (*ps) {
        ps++;
        nt++;
    }
    ps--;  // Puntatore all'ultima lettera di s

    while (*pt) {
        pt++;
    }
    pt--;  // Puntatore all'ultima lettera di t

    while (*ps == *pt) {
        ps--;
        pt--;
        nt--;
    }

    while (*r != '\0') {
        r++;
        nr++;
    }

    if (nr == nt && *pt == '\0') {
        char *pz = z;
        while (s <= ps) {
            *pz = *s;
            pz++;
            s++;
        }
        *pz = '\0';  // Aggiunge il terminatore di stringa alla fine di z
        printf("La stringa z risultante è: %c\n", *pz);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // CONTROLLO DEGLI ARGOMENTI
    if (argc != 4) {
        fprintf(stderr, "Inserisci esattamente 3 parole\n");
        return 1;
    }

    // PRINTF DEL RISULTATO DELLA FUNZIONE
    printf("%d\n", strsubend(argv[1], argv[2], argv[3]));

    return 0;
}