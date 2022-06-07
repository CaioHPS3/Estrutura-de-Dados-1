#include "doubly_list.h"
#include <stdio.h>

int main(){
    List *l=LinkedList_create();
    List *p=LinkedList_create();
    puts("Incerção na cabeça");
    List_add_first(l, 7);
    List_add_first(l, 4);
    List_add_first(l, 2);
    List_add_first(l, 10);
    List_remove(l,4);
    List_print(l);
    List_inverted_print(l);
    puts("Incerção no rabo");
    List_add_last(p, 10);
    List_add_last(p, 2);
    List_add_last(p, 4);
    List_add_last(p, 7);
    List_remove(p,4);
    List_print(p);
    List_inverted_print(p);

    LinkediList_destroy(&p);
    LinkediList_destroy(&l);
    return 0;
}