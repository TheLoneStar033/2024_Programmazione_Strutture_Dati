

#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

#define N 60

int main(int argc, char *argv[]){

    FILE *fp_input, *fp_output, *fp_Oracle;


    if((fp_input=fopen(argv[1], "r"))==NULL)
	{
         fprintf(stderr, "ImPossibile aprire il file input.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_Oracle=fopen(argv[2], "r"))==NULL)
	{
        fprintf(stderr, "Impossibile Aprire il file Oracle.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_output=fopen(argv[3], "w"))==NULL)
	{
        fprintf(stderr, "Impossibile aprire il file output.txt\n");
        exit(EXIT_FAILURE);
    }

    int inmax,result,pos;
    char line[N];
    int num_input[N]={0};
    int num_oracle = 0;
    

    for(int i=1; fgets(line, N, fp_input) != NULL; i++)
	{

        inmax=inputArray(num_input, line, &pos);
        result=somma_array(num_input, inmax);

        
        fgets(line, N, fp_Oracle);
        num_oracle=gg_result(line);

    
        fprintf(fp_output, " %d: %d\n", i, (result==num_oracle));
    }   

    fclose(fp_input);
    fclose(fp_output);
    fclose(fp_Oracle);

}






