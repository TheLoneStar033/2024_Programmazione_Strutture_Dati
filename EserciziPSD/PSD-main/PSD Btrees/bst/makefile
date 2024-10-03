link: bst.o main.o item_int.o
	gcc bst.o main.o item_int.o -o bst.exe

bst.o:
	gcc -c bst.c

main.o:
	gcc -c main.c

item_int.o:
	gcc -c item_int.c

clean:
	rm -f *.o *.exe
