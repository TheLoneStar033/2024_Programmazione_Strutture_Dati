#include "btree.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
  Item value;
  struct node* left;  //Dichiariamo dei puntatori di tipo node
  struct node* right; //Puntatore al nodo right figlio della radice(item value)
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}

//-----------------------COSTRUTTORE ALBERO-----------------------
BTree buildTree(BTree left, BTree right, Item i){ //o q l
  BTree tree=malloc(sizeof(struct node));
  tree->left=left; //puntatore left dell'albero/nodo punta al (puntatore del)albero/nodo dato come parametro "left"
  tree->right=right;
  tree->value=i;
  return tree;
}
//----------------------------------------------------------------

Item getBTreeRoot(BTree tree){ //Stampa la radice dell'albero/sottoalbero
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->value;
}

BTree getLeft(BTree tree){ //Stampa sottoalbero sinistro
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->left;
}

BTree getRight(BTree tree){//Stampa sottoalbero destro
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->right;
}
//------------------------------ VISITE RICORSIVE ---------------------------
void preOrder(BTree tree){
  if(!isEmptyTree(tree)){ //se NON è vuoto
    outputItem(tree->value);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void postOrder(BTree tree){
  if(!isEmptyTree(tree)){
    postOrder(tree->left);
    postOrder(tree->right);
    outputItem(tree->value);
  }
}

void inOrder(BTree tree){
  if(!isEmptyTree(tree)){
    inOrder(tree->left);
    outputItem(tree->value);
    inOrder(tree->right);
  }
}
//---------------------------------------------------------------------------

int uguali(BTree T1, BTree T2) {
  printf("sono nella funzione \n");
	if(isEmptyTree(T1) && isEmptyTree(T2)) return 1;
	if(isEmptyTree(T1) || isEmptyTree(T2)) return 0;
	int *v1= T1->value;
	int *v2= T2->value;

	return *v1==*v2
    && uguali(T1->left,T2->left) 
    && uguali(T1->right,T2->right);
}
 
