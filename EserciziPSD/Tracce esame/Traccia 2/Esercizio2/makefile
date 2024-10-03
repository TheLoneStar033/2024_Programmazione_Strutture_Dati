link: main.o item-int.o list.o btree.o
	gcc main.o item-int.o list.o btree.o -o main.exe

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

list.o:
	gcc -c list.c

btree.o:
	gcc -c btree.c

clean:
	rm -f *.o *.exe