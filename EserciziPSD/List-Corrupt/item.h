//1) creare un item.h
//con tutti i suoi prototipi

typedef void *Item; //Item è un puntatore a void

/*
This means that Item can hold the address of any variable of type void, or it can be set to NULL, 
which indicates that it does not currently hold an address.

The reason for using a pointer to a void is that we want to be able to use the same function to print
items of different types. By using a pointer to a void, we can pass in the address
of any variable of type void and the function will know how to print it.

The Item type is used throughout the code to represent items of different types, 
such as integers, strings, or user-defined data structures.
*/
      
Item inputItem();
void outputItem(Item);
int cmpItem(Item, Item);