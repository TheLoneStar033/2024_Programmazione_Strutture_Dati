#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int conta_parole(char* stringa, char* delimitatori) {
    int num_parole = 0;
    int lunghezza = strlen(stringa);
    int in_parola = 0;

    for (int i = 0; i < lunghezza; i++) {
        if (strchr(delimitatori, stringa[i]) == NULL) {
            if (!in_parola) {
                num_parole++;
                in_parola = 1;
            }
        } else {
            in_parola = 0;
        }
    }

    return num_parole;
}

void stampa_treni_orario(char* orario, char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file %s\n", file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        char partenza[6];
        char arrivo[6];
        int cambi;

        int posizione = 0;
        int lunghezza = strlen(line);
        int campo = 0;
        for (int i = 0; i < lunghezza; i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                if (campo == 0) {
                    partenza[posizione] = '\0';
                } else if (campo == 1) {
                    arrivo[posizione] = '\0';
                } else if (campo == 2) {
                    cambi = atoi(&line[posizione]);
                }
                campo++;
                posizione = 0;
            } else {
                if (campo == 0) {
                    partenza[posizione] = line[i];
                } else if (campo == 1) {
                    arrivo[posizione] = line[i];
                } else if (campo == 2) {
                    posizione++;
                }
            }
        }

        if (strcmp(partenza, orario) == 0) {
            printf("%s %s\n", partenza, arrivo);
        }
    }

    fclose(fp);
}

void stampa_treni_cambi(char* orario, int max_cambi, char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file %s\n", file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        char partenza[6];
        char arrivo[6];
        int cambi;

        int posizione = 0;
        int lunghezza = strlen(line);
        int campo = 0;
        for (int i = 0; i < lunghezza; i++) {
            if (line[i] == ' ' || line[i] == '\n') {
                if (campo == 0) {
                    partenza[posizione] = '\0';
                } else if (campo == 1) {
                    arrivo[posizione] = '\0';
                } else if (campo == 2) {
                    cambi = atoi(&line[posizione]);
                }
                campo++;
                posizione = 0;
            } else {
                if (campo == 0) {
                    partenza[posizione] = line[i];
                } else if (campo == 1) {
                    arrivo[posizione] = line[i];
                } else if (campo == 2) {
                    posizione++;
                }
            }
        }

        if (strcmp(partenza, orario) <= 0 && cambi <= max_cambi) {
            printf("%s %s %d\n", partenza, arrivo, cambi);
        }
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Utilizzo: ./treni <modalita> <orario> [cambi]\n");
        return 1;
    }

    char modalita = argv[1][0];
    char* orario = argv[2];
    int max_cambi = 0;

    if (modalita == 'p' && argc >= 4) {
        max_cambi = atoi(argv[3]);
    }

    char* file = "orari.txt";

    if (modalita == 'q') {
        stampa_treni_orario(orario, file);
    } else if (modalita == 'p') {
        stampa_treni_cambi(orario, max_c
