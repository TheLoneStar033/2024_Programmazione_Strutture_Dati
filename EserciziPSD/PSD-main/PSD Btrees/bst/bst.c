#include "bst.h"
#include "item.h"
#include <stdlib.h>

struct node{
  Item value;
  struct node* left;
  struct node* right;
};

BST newBST(){ //funzione per inizializzare un albero vuoto su cui inserire dopo elementi tramite insert
  return NULL;
}

int isEmptyBST(BST tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}


Item getItem(BST tree){ //restituisce il valore del nodo/albero/sottoalbero
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->value;
}

BST getLeft(BST tree){//restituisce il valore del nodo sinistro figlio del nodo dato come parametro
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->left;
}

BST getRight(BST tree){//restituisce il valore del nodo destro figlio del nodo dato come parametro
  if(isEmptyBST(tree))
    return NULL;
  else
    return tree->right;
}

Item search(BST tree, Item item){ //ricerca di un elemento nell'albero

//Da Analizzare il comportamento per i caratteri invece che i numeri!

/*In questa funzione a differenza delle visite usiamo il return poichè la funzione chiamante deve finire
non dobbiamo tornare nuovamente nella funzione chiamante una volta finita la funzione chiamata a differenza
di quello che abbiamo fatto nelle visite ricorsive*/

  if(isEmptyBST(tree))
    return NULL; //se l'albero è vuoto non c'è nulla da cercare

  if(cmpItem(item,tree->value) == 0)//se l'output della cmpitem è 0 ossia che i due valori corrispondono abbiamo trovato l'item
    return tree->value;

  else if(cmpItem(item,tree->value) > 0)//se l'item cercato è maggiore del nodo attuale
    return search(getRight(tree),item); //andiamo nel sotto albero destro del nodo attuale
    
  else return search(getLeft(tree),item);//se l'item cercato è minore del nodo attuale 
                                         //andiamo nel sotto albero sinistro del nodo attuale

}

Item min(BST tree){
  if(isEmptyBST(tree))
    return NULL;

  while(tree->left != NULL){
        tree = tree->left;
  }
  return tree->value;
}


Item max(BST tree){
  if(isEmptyBST(tree))
    return NULL;

  while(tree->right != NULL){
        tree = tree->right;
  }
  return tree->value;
}

void insertBST(BST *tree, Item item){//dobbiamo modificare l'albero quindi passiamo un puntatore 
  if(isEmptyBST(*tree)){
    *tree = malloc(sizeof(struct node));//allochiamo la memoria per il nodo dell'albero
    (*tree)->left = NULL;  //If you just use *tree instead of (*tree) in line 90, you would be passing 
    (*tree)->right = NULL; //the value of the pointer,not the pointer itself.
    (*tree)->value = item; //Inizializzazione del nodo
  }

  if(cmpItem(item,(*tree)->value) < 0){
    insertBST(&((*tree)->left),item);//se non avessimo usato &() avremmo passato il valore del figlio sinistro del nodo attuale
                                     //invece che il puntatore al figlio sinistro del nodo attuale,
  }
  else if(cmpItem(item,(*tree)->value) > 0){
      insertBST(&((*tree)->right),item);
  }
}
/* In summary, the reason for using &((*tree)->left) at line 96 is to pass a pointer to the left child
pointer of the current node, allowing the function to modify the tree structure. At line 90,
the use of (*tree) is appropriate because it is assigning a new node to the tree pointer itself.*/

Item deleteBST(BST *tree, Item item)
{
  if(isEmptyBST(*tree))
    return NULL;


  if(cmpItem(item,(*tree)->value) < 0){
    return deleteBST(&((*tree)->left),item);
  }
  else if(cmpItem(item,(*tree)->value) > 0){
      return deleteBST(&((*tree)->right),item);
  }
  else
  {
      if(isEmptyBST((*tree)->left))
      {
        Item tempItem = (*tree)->value;
        BST tempBST = *tree;
        *tree = (*tree)->right;
        free(tempBST);
        return tempItem;
      }

      else if(isEmptyBST((*tree)->right))
      {
        Item tempItem = (*tree)->value;
        BST tempBST = *tree;
        *tree = (*tree)->left;
        free(tempBST);
        return tempItem;
      }

      else
      {
        Item maxItem = max((*tree)->left);
        Item tempItem = (*tree)->value;
        (*tree)->value = maxItem;
        deleteBST(&((*tree)->left), maxItem);
        return tempItem;
      }

  }
}
