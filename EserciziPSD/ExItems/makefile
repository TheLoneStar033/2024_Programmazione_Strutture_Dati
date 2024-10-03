
#la strategia si basa sul linkare il tipo che ci serve ogni volta

#link per interi
int: utils.o array.o main.o item_int.o
	gcc utils.o item_int.o array.o main.o -o array.exe

#link per stringhe
string: utils.o array.o main.o item_str.o
	gcc utils.o item_str.o array.o main.o -o array_string.exe

#creare un adt studente per ordinarlo secondo matricola

utils.o: 
	gcc -c utils.c

item_int.o:
	gcc -c item_int.c

item_str.o:
	gcc -c item_str.c
	
array.o: 
	gcc -c array.c

main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe