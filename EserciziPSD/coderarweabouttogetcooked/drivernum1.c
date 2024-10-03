
#include <stdio.h>
#include <stdlib.h>

#include "vettore.h"
#define N 60

int main(int argc, char *argv[]){

    FILE *fp_input, *fp_oracle, *fp_output;
    
    if((fp_input=fopen(argv[1], "r"))==NULL)
	{
         fprintf(stderr, "Impossibile Aprire il file input.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp_output=fopen(argv[3], "w"))==NULL)
	{
        fprintf(stderr, "Impossibile Aprire il file output.txt\n");
        exit(EXIT_FAILURE);
    }
    
    if((fp_oracle=fopen(argv[2], "r"))==NULL)
	{
        fprintf(stderr, "Impossibile Aprire il file Oracle.txt\n");
        exit(EXIT_FAILURE);
    }

    int inmax,inmax2,pos,controllo;
    char line[N];
    int num_input[N]={0}; 
    int num_input2[N]={0}; 
    int num_oracle[N]={0}; 
    

    for(int i=1; fgets(line, N, fp_input) != NULL; i++){

        inmax=inputArray(num_input, line, &pos);
        fgets(line, N, fp_input);
        
        inmax2=inputArray(num_input2, line, &pos);
        fgets(line, N, fp_oracle);//...
        
        inputArray(num_oracle, line, &pos);
    
        somma_array(num_input, num_input2, &inmax, &inmax2 );
      
        fprintf(fp_output,"Prova %d:%d\n", i, Contr_OracleArray(num_input, num_oracle, inmax));
    }

    fclose(fp_input);
    fclose(fp_oracle);
    fclose(fp_output);
}
