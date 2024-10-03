#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOME_FILE "laghi.txt"
#define LLEN 256
#define WLEN 80

void laghiInRegione(const char *regione,char *line,char *nome,char *regioni, FILE *fp) {
        
        int found;
        if (strstr(regioni, regione) != NULL) { //questa funzione Ë una substr cerca nella funzione una precisa sottostringa utilizzabile solo negli esercizi con i file
        //e non negli esercizi con le stringhe
            printf("Il lago presente in questa regione Ë: %s\n", nome);
            found = 1;
        }
    
    if (!found) {
        printf("Nessun lago trovato in questa regione.\n");
    }
    
}


int main (int argc, char *argv[]) {

//---------------------------------controllo apertura file -------------------------------
    FILE *fp;
    
    if ( (fp=fopen(NOME_FILE, "r"))  == NULL  ) {
      
        fprintf(stderr, "Non posso aprire il file %s\n", NOME_FILE);
        exit(EXIT_FAILURE);
    }
    
    /* controllo argomenti: in questo primo file avremo solo 2 
     argomenti, l'eseguibile e il nome del lago. */
    
    if (argc!=2) {
        fprintf(stderr, "Uso errato: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
/* -------------------------------- svolgimento esercizio -------------------------- */
    
    char line[LLEN+1], nome[WLEN+1], regioni[2*WLEN+1];
    int area, alt, prof, n;
    
    while ( fgets(line, sizeof(line), fp) ) {  
    //legge una riga dal file puntato da fp e continua ad eseguire il suo corpo fintanto che la funzione fgets restituisce un valore diverso da NULL.
    
        n=sscanf(line, "%[^0123456789] %d %d %d %[^\n]", nome, &area, &prof, &alt, regioni);
        	//printf("N uguale a:%d",n);
        //---------------------------------------------ZONA DI CONTROLLO--------------------------------------------------
		//printf("N equals to: %d",n);
        //aggiungere un messaggio di errore e di exit se n!=5
        
        /* facciamo sempre stampe di controllo per verificare la sscanf ha correttamente allocato le variabili.
         Una volta che abbiamo controllato che tutto √® ok,
         le cancelleremo dal file*/
        // printf("%d\n", area);
        // printf("%d\n", prof);
        //printf("%d\n", alt);
        //printf("%s\n", regioni);
        //printf("\n"); 

        /* Abbiamo un problema nella stringa nome: oltre al nome del lago,
         abbiamo anche gli spazi di separazione tra il nome del lago
        e l'intero.
         Questa printf della lunghezza di nome ce lo evidenzia.
         */
        
        // printf("%s, %lu\n", nome, strlen(nome));
         
        /* perci√≤ la strcmp non funziona correttamente...
         Eseguiamo passando Garda... vedremo che il programma non
         lo trova... Venerd√¨ risolviamo...
         -----------------------------------------------------------------------------------------------------------------*/
        
		laghiInRegione(argv[1],line,nome,regioni,fp);
        
        //Se strncmp restituisce 0, significa che le due stringhe sono identiche. strncmp confronta se le due stringhe sono uguali fino al numero di caratteri specificato nel terzo
		//argomento, in questo caso fino al quinto di nome, carattere se inseriremo Garda, cosÏ non considerer‡ gli spazi presenti nel file.
        if (strncmp(argv[1],nome,strlen(argv[1]))==0) { 
		
            printf("%s %s", nome, regioni);
        }
        
    } // --------------------------------------------- --------------------------------- fine while -----------------------------------------------------------
    
    
    
    fclose(fp);
    return 0;
}

