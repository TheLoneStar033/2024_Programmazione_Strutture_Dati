int: list.o main.o item_int.o
	gcc list.o item_int.o main.o -o list.exe

string: list.o main.o item_string.o
	gcc list.o item_string.o main.o -o list.exe

libro: list.o libro.o item_libro.o catalogo.o main2.o
	gcc list.o libro.o item_libro.o catalogo.o main2.o -o libro.exe

list.o: 
	gcc -c list.c

libro.o:
	gcc -c libro.c

item_libro.o:
	gcc -c  item_libro.c

catalogo.o:
	gcc -c catalogo.c

main2.o:
	gcc -c main2.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe