#include "doubly_list.h"
#include <stdio.h>

int main(){
    List *l=LinkedList_create();

    List_add_first(l, 7);
    List_add_first(l, 4);
    List_add_first(l, 2);
    List_add_first(l, 10);

    List_print(l);
    List_inverted_print(l);


    LinkediList_destroy(&l);
    return 0;
}