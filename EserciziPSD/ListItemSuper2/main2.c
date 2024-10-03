#include <stdlib.h>
#include "list.h"
#include "item.h"
#include <stdio.h>

 void minlist(List list,Item *min){
    if(!isEmpty(list)){

    Item p=getHead(list);
    removeHead(list);

         if(cmpItem((*min),p)>0){
            *min=p;
        }
    minlist(list,min);
    addHead(list,p); 
    }
 }

   void mintotail1(List list){
        if (!isEmpty(list)) {
        Item min = getHead(list); //inizializzo item min
        minlist(list, &min); //passo min alla funzione, min verrà modificato

        removeListItem(list, min);

        addListTail(list, min);
    }
}
   
    


int main(){
    /*
    List list = newList();

    for(int i=0;i<2;i++)
    {
        Item item=inputItem();
        addHead(list,item);
    }
    printList(list);
    Item item=inputItem();
    ListFilterFilt(&list,item);
    printList(list);
    */

   List list = newList();

    for(int i=0;i<4;i++)
    {
        Item item=inputItem();
        addHead(list,item);
    }
    printList(list);
    //reverseList(&list);
    //mintotail(&list);
    //printList(list);

    /*
    //----------------------------------ADDMINTOTAIL FUNCTION-------------------------------
    //CREO UNA COPIA DELLA LISTA 
    List copyList = cloneList(list);
   
    //CALCOLO MINIMO SULLA COPIA:
    Item min = getHead(copyList); 
    minlist(copyList,&min); //La lista viene modificata anche senza dare il puntatore
    printf("\ncopylist:");
    printList(copyList);

    //CONTROLLO MINIMO
    printf("\n");
    outputItem(min);

    //ADDMINTOTAIL
    removeListItem(list,min);
    addListTail(list,min);

    //CONTROLLO ADDMINTOTAIL
    printf("mintotail: \n");
    printList(list);
    //---------------------------------------------------------------------------------------
    */
    printf("mintotail: \n");
    mintotail1(list);
    printList(list);
    return 0;

}



