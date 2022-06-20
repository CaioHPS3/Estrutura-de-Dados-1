#include "circ_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _circ_note {
    int val;
    struct _circ_note *prev;
    struct _circ_note *next;
    
}CircNode;
typedef struct _circ_list {
    CircNode *begin;
    CircNode *end;
    int size;
}CircList;

//cria um nó e adiciona um valor
CircNode *CircNode_create(int val){
    CircNode *cnode = calloc(1, sizeof(CircNode));
    cnode->val=val;
    cnode->prev=cnode;
    cnode->next=cnode;

    return cnode;
}
//Desaloca um nó
void CircNode_destroy(CircNode **cnode_ref){
    CircNode *cnode = *cnode_ref;
    free(cnode);
    cnode_ref=NULL;
}
//cria uma lista
CircList *CircList_create(){
    CircList *L= calloc(1, sizeof(CircList));
    L->begin= NULL;
    L->end= NULL;
    L->size =0;
    return L;
}
//desaloca uma lista (e os nós que estão dentro)
void CircList_destroy(CircList **L_ref){
    CircList *l = *L_ref;
    CircNode *p= l->begin;
    CircNode *aux= NULL;
    //Enquanto a lista não chegar no seu ultimo nó
    //vai desalocando os nós
    while(p!=l->end){
        aux= p;
        p=p->next;
        CircNode_destroy(&aux);
    }
    //depois desalocar o último nó
    CircNode_destroy(&p);
    free(l);
    L_ref=NULL;
}
void CircList_destroy2(CircList **L_ref){
    CircList *l = *L_ref;
    CircNode *p= l->begin;
    CircNode *aux= NULL;
    //como sabemos o tamanho da lista podemos desalocar usando
    // o laço de repetição for
    for(int a= 0;a<l->size;a++){
        aux= p;
        p=p->next;
        CircNode_destroy(&aux);
    }
    free(l);
    L_ref=NULL;
}
bool CircList_is_empty(const CircList *L){
    return L->size == 0;
}
