#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "playlist.h"


// utilizzare questa funzione nel main per <stampare, ordinare, stampare> la playlist
// da completare riga ***
void stampaEordina(Playlist pl){
	printf("\n-- Stampa playlist originale --\n");
	printPlaylist(pl);
	printf("\n-- Stampa playlist dopo ordinamento per gradimento --\n");

	// *** inserire qui la chiamata all'operatore che ordina la playlist per gradimento
	//sortByGradimento(pl);

	printPlaylist(pl);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 100
int randomInt() {
	return 1 + (rand() % 100);
}

int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

	// completare
}
