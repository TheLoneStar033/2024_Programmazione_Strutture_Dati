#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "espressione.h"
#include "item.h"
#include "stack.h"
#define N 30

int main()
{

    char exp[N];
    printf("inserisci l'espressione: ");
    scanf("%[^\n]", exp);
    if(isBalanced(exp))
        printf("L'espressione e' bilanciata");
    else
        printf("L'espressione non e' bilanciata");
}
