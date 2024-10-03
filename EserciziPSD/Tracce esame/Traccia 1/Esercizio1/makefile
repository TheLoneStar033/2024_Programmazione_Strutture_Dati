link: item-song.o song.o list.o main.o playlist.o
	gcc item-song.o song.o list.o main.o playlist.o -o playlist.exe

item-song.o:
	gcc -c item-song.c

song.o:
	gcc -c song.c

list.o:
	gcc -c list.c

playlist.o:
	gcc -c playlist.c

main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe