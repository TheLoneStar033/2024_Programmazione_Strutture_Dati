#include <stdio.h>
#include <stdlib.h>

void asporto(char *s, char *t, char *z) {
    char *ps = s, *pt = t, *pz = z;

    while (*ps == *pt) {
        if (*ps == '\0' || *pt == '\0') {
            break;
        }
        ps++;
        pt++;
    }

    while (*ps != '\0') {
        *pz = *ps;
        pz++;
        ps++;
    }

    while (*pt != '\0') {
        *pz = *pt;
        pz++;
        pt++;
    }

    *pz = '\0';  // Aggiunge il terminatore di stringa alla fine di z
    printf("La stringa z risultante è: %s\n", z);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Utilizzo: ./programma <stringa_s> <stringa_t> <stringa_z>\n");
        return 1;
    }

    char *s = argv[1];
    char *t = argv[2];
    char z[100];  // Assumiamo una dimensione massima per la stringa z

    asporto(s, t, z);

    return 0;
}
