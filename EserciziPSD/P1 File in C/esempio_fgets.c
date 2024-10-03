#include <stdio.h>
#include<string.h>

int main(void)
{
  
   
    char parola[10];
    
    printf("Inserisci una frase di al massimo 9 caratteri:\n");
    //provate a inserire una di 20 caratteri, ad esempio.
    
    fgets(parola, sizeof(parola), stdin) ; 
	//La funzione fgets legge una linea dallo stream di input e la memorizza nel buffer 
	//puntato da line. Il secondo argomento sizeof(line) specifica la dimensione massima
	//del buffer, mentre il terzo argomento fp è un puntatore al file da cui leggere la linea.
    
    printf("%s\n", parola); //stampato la parola corrente
    

 return 0;
 }

