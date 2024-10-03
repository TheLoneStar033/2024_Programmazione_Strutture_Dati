#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.dat"

int main(void)
{

    FILE *fp;
    fp = fopen(FILE_NAME, "r"); // apre example.dat per leggere


    if (fp == NULL)
    {
        printf("Impossibile aprire il file %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}
