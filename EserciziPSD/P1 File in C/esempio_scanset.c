#include<stdio.h>
#include<string.h>

int main(void) {

    char str[200]="Garda 370     346   65   Lombardia Veneto Trentino-Alto-Adige";
 
 /* -------- SSCANF STATICO --------------------------------------------------------------------------------
 
    char lago[20], regioni[80];
    int  area, alt, prof;
    
    if (sscanf(str, "%s %d %d %d %[^\0]", lago, &area, &prof, &alt, regioni) ==5) {
        printf("%s\n", lago);
        printf("%d\n", area);
        printf("%d\n", prof);
        printf("%d\n", alt);
        printf("%s\n", regioni);
    }
 */
    
    
/* ---------- ora scriviamo un ciclo di sscanf che "scandisce" str, parola per parola (DINAMICO) -------- */
    
    char *temp=str; //inizializzo puntatore temp all'inizio di str
    int num_parole=0; 
    char parola[50];
    
    while(sscanf(temp, "%s", parola)==1 ) { //mentre la condizione sscanf è possibile (mettere in parola il valore puntato da temp) esegue la sscanf + ciò nel ciclo
        
        printf("%s\n", parola);
        num_parole++;
        
        temp= temp+strlen(parola)+1;
        while (*temp==' ') temp++; //nel caso temp stia puntando a uno spazio viene incrementata fino a quando non punta ad un carattere.
    }
    
    printf("Numero parole:%d\n", num_parole);
    
return 0;
}



