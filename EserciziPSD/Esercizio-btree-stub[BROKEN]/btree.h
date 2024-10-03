#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void SommaAlbero(BTree,int*);
void insertBST(BTree *, Item);


BTree newRandomTree(int);

void printTree(BTree);

