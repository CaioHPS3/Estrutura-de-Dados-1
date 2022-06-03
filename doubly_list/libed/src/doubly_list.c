#include "doubly_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct _doubly_node {
    int val;
    struct _doubly_node *prev; //anterior
    struct _doubly_node *next; //proximo
}DoublyNode, Node;

typedef struct _doubly_linked_list {
    Node *begin;
    Node *end;
    int size;
}DoublyLinkedList, List;
//cria os nó da lista
Node *Node_create(int val) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    if(node==NULL){
        return 0;
    }
    // os dois ponteiros next que aponta para o proximo nó
    //e o prev que aponta para o anterior
    node->prev = NULL;
    node->next = NULL;
    node->val = val;

    return node;
}
//cria a cabeça da lista
List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}
//desaloca a lista
void List_destroy(List **L_ref) {
    List *L = *L_ref;

    Node *p = L->begin;
    Node *aux = NULL; 

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}
//verifica se a lista estar vazia
bool List_is_empty(const List *L){
    return L->size == 0;
}
// incerção no começo da lista
void List_add_first(List *L, int val){
    Node *p = Node_create(val);
    //se a lista estiver vazia
    if(List_is_empty(L)){
        L->end = p;
    }
    //se a lista ja tiver elementos
    // mesma logica da linked_list
    else{
        p->next=L->begin;
        // o nó do começo do lista vai aponta para o novo nó
        //apotando para traz  
        L->begin->prev=p;
    }
    //novo primeiro nó
    L->begin=p;
    L->size++;
}
//inseri um nó no final da lista
// ver a logica no LDouble
void List_add_last(List *L, int val){
    Node *novo=Node_create(val);
    if(L->begin){
        L->begin=novo;
        L->size++;
    }else{
        novo->prev=L->end;
        L->end->next=novo;
    }
    L->end=novo;
}
//imprime a lista 
void List_print(const List* L){
    
    if(L==NULL) return;
    
    Node *aux = L->begin;

    printf("L_Begin --> ");
    
    while(aux){
        printf("%d --> ", aux->val);
        aux=aux->next;
    }
    printf("NULL\n");

}
void List_inverted_print(const List* L){
    
    if(L==NULL) return;
    
    Node *aux = L->end;

    printf("NULL");
    
    while(aux){
        printf(" <-- %d ", aux->val);
        aux=aux->prev;
    }
    printf(" <-- end_L\n");

}
