link: btree.o item_int.o list.o main.o
	gcc btree.o item_int.o list.o main.o -o btree.exe

btree.o:
	gcc -c btree.c

item_int.o:
	gcc -c item_int.c

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe