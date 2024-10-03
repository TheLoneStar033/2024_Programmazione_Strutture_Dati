#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void RightNodeOnly(BTree tree, int *count);
Item deleteNode(BTree *tree, Item item);

BTree newRandomTree(int);

void printTree(BTree);

