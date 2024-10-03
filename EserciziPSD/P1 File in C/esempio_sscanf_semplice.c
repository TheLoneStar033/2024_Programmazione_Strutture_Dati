#include <string.h>
#include <stdio.h>
#define SET "%[^0123456789]"
#define SET1 ^0123456789
#define ALPHA abcdefghijklmnopqrstuvz


int main(void) {
   char str[180] = "Garda 370 346 65 Lombardia Veneto Trentino-Alto-Adige";
   char parola[50], fine[20];

   sscanf(str, SET, parola);        //Qui strlen è uguale a 6 perchè viene incluso anche lo spazio in parola
   printf("%lu\n", strlen(parola));
   puts(parola); 
   
   sscanf(str, "%[SET1]", parola);  //Non fa nulla macro non definita correttamente
   printf("%lu\n", strlen(parola));
   puts(parola); 

   sscanf(str, "%[ALPHA]", parola);  //Non fa nulla macro non definita correttamente
   printf("%lu\n", strlen(parola));
   puts(parola); 

   sscanf(str, "%[A-Za-z]", parola); //Qui strlen è uguale a 5 perchè non viene incluso anche lo spazio in parola
   printf("%lu\n", strlen(parola));
   puts(parola); 

   sscanf(str, "%[^-]%[^'\n']", parola, fine); //in questo caso parola si ferma al primo "-" che incontra, mentre la stringa fine acquisice tutti i caratteri
   //a partire da quel trattino fino alla fino al carattere di fine riga come specificato dalla seconda specifica di conversione [^\n] che si riferisce a fine
   printf("%lu\n", strlen(parola));
   puts(parola); 
    printf("%lu\n", strlen(fine));
   puts(fine); 

   sscanf(str, "%[^-]-%[^\n]", parola, fine); // il carattere - in mezzo alle due specifiche sta a significare che se subito dopo l'acquisizione di parola vi è uno "-" esso va
   //ignorato e non verrà inserito nella parola fine.
   printf("%lu\n", strlen(parola));
   puts(parola); 
    printf("%lu\n", strlen(fine));
   puts(fine); 

   printf("Cambio parola e inserisco \\n\n");

   char str1[180] = "Garda 370 346 65 Lombardia Veneto Trentino-Alt\no-Adige";
   sscanf(str1, "%[^-]%[^\n]", parola, fine);// in questo caso evinciamo un dettaglio particolare, che se non vogliamo fare in modo che il carattere newline non venga
   //preso dobbiamo anche ricordare che anche il carattere \n in mezzo alla stringa non verrà considerato.
   printf("%lu\n", strlen(parola));
   puts(parola); 
    printf("%lu\n", strlen(fine));
   puts(fine);
    
   return 0;
}

