link: item-string.o main.o queue-array.o
	gcc item-string.o main.o queue-array.o -o main.exe

item-string.o:
	gcc -c item-string.c

main.o:
	gcc -c main.c

queue-array.o:
	gcc -c queue-array.c

clean:
	rm -f *.o *.exe