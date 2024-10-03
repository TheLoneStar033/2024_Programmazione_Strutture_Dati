#include <stdio.h>
#include "list.h"
#include "item.h"

// Dato un titolo, restituisce 1 se la canzone esiste, 0 altrimenti
int exists(List playlist, char *title) {
    int pos;
    Item song = searchListItem(playlist, (void *)title, &pos);
    return pos!= -1;
}

// Aggiunge una canzone alla playlist
void addSong(List playlist, char *title, char *artist, int duration) {
    Item song = createItem(title, artist, duration);
    addHead(playlist, song);
}

// Rimuove una canzone dalla playlist
void removeSong(List playlist, char *title) {
    Item song = removeListItem(playlist, (void *)title);
    freeItem(song);
}

// Ordina la playlist in base al titolo delle canzoni
void sortPlaylist(List playlist) {
    sortList(playlist, (int (*)(const void *, const void *))cmpItem);
}

// Crea una nuova playlist
List createPlaylist(char *name) {
    List playlist = newList();
    Item info = createItem(name, NULL, 0);
    addHead(playlist, info);
    return playlist;
}


int main() {
    List playlist = createPlaylist("Rock");

    addSong(playlist, "Song 1", "Artist 1", 120);
    addSong(playlist, "Song 2", "Artist 2", 180);
    addSong(playlist, "Song 3", "Artist 3", 240);
    addSong(playlist, "Song 4", "Artist 4", 300);
    addSong(playlist, "Song 5", "Artist 5", 360);

    // Verifica se la playlist contiene una canzone con il titolo specificato
    if (exists(playlist, "Song 3")) {
        printf("Song 3 exists\n");
    } else {
        printf("Song 3 does not exist\n");
    }

    // Rimuove la canzone con il titolo specificato
    removeSong(playlist, "Song 4");

    // Ordina la playlist in base al titolo delle canzoni
    sortSongs(playlist);

    // Stampa la playlist ordinata
   
    return 0;
}