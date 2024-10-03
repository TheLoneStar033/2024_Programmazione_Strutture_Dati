link: item-char.o stack.o main.o utils.o 
	gcc item-char.o stack.o main.o utils.o -o stack.exe

item-char.o:
	gcc -c item-char.c

stack.o:
	gcc -c stack.c 

main.o:
	gcc -c main.c 

utils.o:
	gcc -c utils.c

clean:
	del -f *.exe *.o