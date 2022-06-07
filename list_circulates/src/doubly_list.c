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
    novo->prev=L->end;
    // se a lista estiver vazia
    if(List_is_empty(L)){
        L->begin=novo;
    }else{
        L->end->next=novo;
    }
    L->end=novo;
    L->size++;
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
//print de de traz para frente
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
void List_remove(List *L, int val){
    //se a lista não estiver vazia
    if(!List_is_empty(L)){
        //Caso o elemento esteja na cabeça da lista
        if(L->begin->val==val){
            Node *p= L->begin;
            //se a lista estiver um unico nó
            if(L->begin==L->end){
                L->begin= L->end=NULL;

            }//se tiver mais de um nó
            else{
                L->begin=L->begin->next;
                L->begin->prev=NULL;
            }
            free(p);
            L->size--;
        }//Caso nó esteja no meio da lista ou no final
        else{
            Node *p= L->begin->next;
            while(p!=NULL){
                if(p->val == val){
                    //caso o nó seja o ultimo da lista
                    if(p->next==NULL){
                        //se o nó anterior a p(o que eu quero remover) o ponteiro next dele vai apontar para Null
                        p->prev->next=NULL;
                        //corrigindo o encadeamento que agora o último nó e o antigo penultimo
                        L->end=p->prev;
                    }//caso o nó esteja no meio
                    else{
                        //corrigindo o encadeamento  
                        //O nó anterior de (p) vai aponta para o nó seguinte ao (p)
                        p->prev->next=p->next;
                        //O nó seguinte ao (p) vai aponta para o nó anterior a (p)
                        p->next->prev=p->prev;
                    }
                    free(p);
                    p=NULL;
                    L->size--;
                }else p = p->next;
            }
        }
    }
}
