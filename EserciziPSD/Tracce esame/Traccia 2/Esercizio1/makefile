link: item.o main.o list.o stack.o
	gcc item.o main.o list.o stack.o -o main.exe

item.o:
	gcc -c item.c

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

stack.o:
	gcc -c stack.c

clean:
	rm -f *.o *.exe