#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "example.dat"

int main(void)
{
	/*
    char sex[5];
    char str[11]; // Aumentato a 11 per consentire spazio per il carattere terminatore
    
    int n = scanf("%10[^0123456789\n ] %4s", str, sex); // Limitato a 10 caratteri per str e 4 caratteri per sex
    printf("n: %d str: %s sex: %s\n", n, str, sex);
    printf("%lu", strlen(str));
    */
    
    //oppure
    
    char parola[10];
    
    printf("Inserisci una frase di al massimo 9 caratteri:\n");
    //provate a inserire una di 20 caratteri, ad esempio.
    fgets(parola, sizeof(parola), stdin) ;
    printf("%s\n", parola); //stampato la parola corrente
    
    
    return 0;
}
