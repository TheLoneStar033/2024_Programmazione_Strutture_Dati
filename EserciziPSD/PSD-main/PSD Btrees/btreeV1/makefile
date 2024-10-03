link: btree.o main.o item_string.o
	gcc btree.o main.o item_string.o -o btree.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.o *.exe
