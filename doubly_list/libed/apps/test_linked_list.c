#include "linked_list.h"
#include <stdio.h>

int main(){
    LinkedList *L = LinkedList_create();
    LinkedList *P = LinkedList_create();
    printf("Insercao no inicio");
    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 20);
    LinkedList_add_first(L, 30);
    LinkedList_add_first(L, 40);
    LinkedList_add_first(L, 50);
    LinkedList_add_first(L, 60);
    LinkedList_remove(L, 50);
    LinkedList_print(L); 
    LinkedList_remove(L, 10);
    LinkedList_print(L);
    printf("O primeiro %d\n", LinkedList_first_val(L));
    printf("O último %d\n", LinkedList_last_val(L));
    printf("O valor que estar no indice 2 e = %d\n", LinkedList_get_val(L, 2));
  
 
    printf("Insecao no final\n");
    LinkedList_add_last(P, 10);
    LinkedList_add_last(P, 20);
    LinkedList_add_last(P, 30);
    LinkedList_add_last(P, 40);
    LinkedList_add_last(P, 50);
    LinkedList_add_last(P, 60);
    LinkedList_print(P);
    LinkedList_remove(P, 30);
    LinkedList_print(P);
    LinkedList_remove(P, 60);
    LinkedList_print(P);
    LinkedList_size(P);
    printf("O primeiro %d\n", LinkedList_first_val(P));
    printf("O último %d\n", LinkedList_last_val(P));
    printf("O valor que estar no indice 2 e = %d\n", LinkedList_get_val(P, 2));
    

    LinkediList_destroy(&L);
    LinkediList_destroy(&P);
    
    return 0;
}