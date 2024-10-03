#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME_FILE "montagne.txt"

int main(int argc, char *argv[]) {
    FILE *fp;
    if ((fp = fopen(NOME_FILE, "r")) == NULL) {
        fprintf(stderr, "Non posso aprire il file");
        exit(EXIT_FAILURE);
    }

    if (argc >3) {
        fprintf(stderr, "Uso Sbagliato Utilizzo: NOME_ESEGUIBILE.exe\n");
        fprintf(stderr, "NOME_ESEGUIBILE.exe PAESE\n");
        fprintf(stderr, "NOME_ESEGUIBILE.exe Montagna\n");
        fprintf(stderr, "NOME_ESEGUIBILE.exe intervallo1 intervallo2\n");
        exit(EXIT_FAILURE);
    }
	
	int inputtype;
	if(argc==2)
	{
		inputtype=1;
	}
	
	else if(argc==3)
	{
		if(atof(argv[3])<10000)
		inputtype=2;
		else inputtype=3;
		
	}
	printf("%d",inputtype);
		

    char line[100], nome[20], paesi[30];
    int pos, altezza, n;
    while (fgets(line, sizeof(line), fp)) {
        n = sscanf(line, "%d %[^:]: %d %[^\n]", &pos, nome, &altezza, paesi);
        if (n == 4) {
            //printf("%d %s: %d %s\n", pos, nome, altezza, paesi);
        }
		
		if (inputtype==1)
		{
			//printf("%s",nome);
			//printf("%s",argv[1]);
			if(strncmp(argv[1],nome,strlen(argv[1]))==0)
				printf("%d m",altezza);
		}
    }

    fclose(fp);
    return 0;
}