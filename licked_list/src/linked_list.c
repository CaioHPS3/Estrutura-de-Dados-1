#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snote{
    int val;
    struct _snote *next;
}SNode;

typedef struct _linked_list{
    SNode *begin;
    SNode *end;
    int size;
}LinkedList;

//Cria um Nó e adiciona um valor ao Nó e para lugar nem um 
SNote *SNote_create(int val){
    SNode *snote =(SNode*) calloc(1, sizeof(SNode));
    snote->val=val;
    snote->next=NULL;
    
    return snote;
}

//Cria a cabeça da lista encadeada onde ela vai apontar para o primeiro nó da lista 
LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin =NULL;
    L->end = NULL;
    L->size=0;

    return L;
}
// desaloca o que foi alocado
void LinkediList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *p= L->begin;
    SNode *aux= NULL;
    
    while (p != NULL)
    {
        aux=p;
        p=p->next;
        free(aux);

    }
    free(L);

    L_ref = NULL;
    
}
bool LinkedList_is_empty(const LinkedList *L){
    return L->size==0;
}
// Vai criar e adiciona um item em um nó e fazer a cabeça da lista apontar para o nó que acabou de ser criado
// Uma inserção na cabeça (INICIO) da lista 
void LinkedList_add_first(LinkedList *L, int val){
    
    //Será criado um nó e adicionado um valor nele
    SNode *p = SNote_create(val);
    //ele vai apontar para o mesmo lugar que a cabeça da função
    //que é o primeiro nó da lista ou se a lista estiver vazia vai aponta para NULL
    p->next= L->begin;

    if(LinkedList_is_empty(L)){
        /* 
            Se a lista estiver vazia ele vai aponta para o primeiro nó
            nas proximas chamadas da função ele não será mais chamado pois ele só aponta
            aponta para o último nó e a inserção e no cabeça (INICIO)
        */ 
        L->end = p;
    }
    //a begin(cabeça da lista) vai aponta para o p fazendo que ele seja o primeiro item da lista
    //inserção no inicio
    L->begin = p;
    L->size++;
}
//Vai cria e adiciona um item ne um nó
// Uma inserção na calda da lista (Final)
void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = SNote_create(val);
    // se a lista estiver vazia vai aponta para q
    if(LinkedList_is_empty(L)){
        L->begin = q;
    }
    //se a lista estiver com algum nó
    else{
        //Vai ser criado uma variavel para auxiliar que vai andar a lista de nó
        // p apontando para o mesmo nó de begin (o primeiro nó)
        SNode *p=L->begin;
        /*
            Enquanto o endeço de p for igual a um endereço valido ela vai
            pulando para o proximo nó, quando ele encontrar NULL então ele chegou ao ultimo 
            nó da lista
        */
        while (p->next != NULL)
        {
            p=p->next;
        }
        //chegando no ultimo nó da lista, esse nó vai aponta para o novo nó que vai ser inserido
        //assim inserindo o novo nó calda da lista (no final)
        //corrigindo o encadeamento último nó apotando para o novo último nó
        p->next=q;
    }
    L->size++;
}
//Vai cria e adiciona um item ne um nó
// Uma inserção na calda da lista (Final) só que mais rapido
void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = SNote_create(val);
    // se a lista estiver vazia vai a cabela e calda aponta para q 
    if(LinkedList_is_empty(L)){
        L->begin =q;
        L->end =q;
    }
    // se a lista esviver com algum nó
    else{
        /*
            End aponta para o último nó
            End vai aponta para o ponteiro do uĺtimo nó e vai fazer ele aponta para q
            corrigindo o encadeamento fazando o último nó apota para o novo ultimo nó

        */
        L->end->next=q;
        //end vai aponta para o novo último nó
        //L->end=L->end->next;
        L->end=q;
    }
    L->size++;
}
//Vai printar o valor de cada nó
void LinkedList_print(const LinkedList *L){
    //p vai apontar para o mesmo lugar que begin, para o primeiro nó
    SNode *p = L->begin;
    //e estabelecido um laço de repetição no qual vai rodar enquanto p não apontar para NULL
    printf("L -->");
    while(p != NULL){
        //vai ser imprimir o que estiver no nó
        printf(" %d --> ", p->val);
        //p vai apontar para onde o nó estar apontando (o proximo nó) rodando assim ate chegar no
        //ultimo nó que aponta para NUUM 
        p= p->next;
    }
    printf("NULL\n");
    if(L->end==NULL){
    printf("L->end == NULL");

    }else{
        printf("L->end = %d\n", L->end->val);
    }
    printf("Size %d", L->size);
    puts("");
    
}
//vai remover os nós da lista
void LinkedList_remove_p(LinkedList *L, int val){
    //se a lista não (!) estiver vazia 
    if(!LinkedList_is_empty(L)){
        //Caso 1 se o val estiver no primeiro nó da lista
        if(L->begin->val==val){
            //vai ser criado um variavel pos que vai aponta para onde begin estar apontando
            //o primeiro nó da lista
            SNode *pos= L->begin;
            //Caso a lista so tem um nó esse nó e a cabeça e a calda
            // ele será removido
            if(L->begin == L->end){
                L->end = NULL;
            }
            //begin vai aponta para o segundo nó da lista que o endereço que estar no primeiro nó
            // que vai ser null
            L->begin = L->begin->next;
            //pos vai ser desalocado (com ele o nó para onde ele aponta)
            free(pos);
            L->size--;
        }
        //Caso o nó estiver no meio da lista
        else{
            /* 
                Vai ser criado duas variaveis as quais vão guarda dois endereço
                prev vai aponta para o primeiro nó da lista
                pos vai aponta para o segundo nó da lista já que a lista tem mais de um nó
            */
            SNode *prev = L->begin;
            SNode *pos =L->begin->next;
            /*
                Enquanto pos não chegar ao final da lista (== NULL)
                e pos não achar o valor desejado no nó
                prev vai aponta para o proximo nó da lista
                (para onde pos estava apontando e não encontrado o nó desejado)
                pos vai apontar para o proximo nó se houver (!= NULL)
            
            
            */
            while(pos != NULL && pos->val != val){
                prev=prev->next;
                pos= pos->next;
            }
            //se o while for interronpido e pos é diferente de null então o nó foi encontrado
            // no meio da lista
            if(pos !=NULL){
                /*
                    prev vai corrigir o encadeamento, recebendo o endereço do nó que
                    estar apos do que vai ser removido (para onde pos está apontando)
                    depois com o encadeamento corrigido pos e desalocado
                */
                prev->next= pos->next;
                /*
                    Caso 3 remove o ultimo elemento da lista
                    se o nó de pos aponta para NULL então ele é 
                    o ultimo nó da lista, desta forma vai ser corrigido
                    o encadeamento de "end" vai aponta para onde prev estar apontando
                */
                if(pos->next == NULL){
                    L->end= prev;
                }
                free(pos);
                L->size--;
            }

        }
    }
}
// remove nós só que o logica estar mais fluida
void LinkedList_remove(LinkedList *L, int val) {
    if (!LinkedList_is_empty(L)) {
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        // se achou um nó com valor val
        if (pos != NULL) {
            if (L->end == pos) {
                L->end = prev;
            }
            if (L->begin == pos) {
                L->begin = L->begin->next;
            }
            else {
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
        }
    }
}
int LinkedList_size_slow(const LinkedList *L){
    int size=0;
    SNode *p = L->begin;

    while(p!=NULL){
        size++;
        p= p->next;
    }
    //ou
    
    // for(p=L->begin; p!=NULL; p= p->next){
    //     size++;
    // }

    return size;

}
int LinkedList_size(const LinkedList *L){
    return L->size;
}

int LinkedList_first_val(const LinkedList *L){
    if(L->begin==NULL){
        printf("Lista esta vazia\n");
        return 0;
    }
    else{ 
        return L->begin->val;
    }
    
    return 0;
}
int LinkedList_last_val(const LinkedList *L){
    if(L->begin==NULL){
        printf("Lista esta vazia\n");
        return 0;
    }
    else{ 
        return L->end->val;
    }

}
int LinkedList_get_val(const LinkedList *L, int index){
    if(L->begin==NULL){
        printf("Lista esta vazia\n");
    } 
    if(index < 0 || index >= L->size){
        printf("Index invalido\n");
    }else{
        int i=0;
        SNode *p= L->begin;
        while(i!=index){
            p=p->next;
            i++;
        }
        return p->val;
    }


}