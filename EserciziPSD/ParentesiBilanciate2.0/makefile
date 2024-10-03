link: stackList.o main.o list.o espressione.o item.o
	gcc stackList.o main.o list.o espressione.o item.o -o exp.exe

test: item.o main.o
	gcc item.o main.o -o test.exe

stackList.o:
	gcc -c stackList.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

espressione.o:
	gcc -c espressione.c

item.o:
	gcc -c item.c

clean:
	rm -f *.o *.exe