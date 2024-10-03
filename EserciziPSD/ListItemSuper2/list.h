#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List); 
Item searchListItem(List, Item, int *);
Item removeListItem(List, Item);
Item removeListPos(List, int);
List ListFilter(List *list,Item item);
void ListFilter2(List *list,Item item);
void ListFilterFilt(List *list,Item item);
void mintotail(List *list);





//
int addListPos(List, Item, int);
int addListTail(List, Item);
void reverseList(List*);
List cloneList(List);
List cloneListItem(List);
