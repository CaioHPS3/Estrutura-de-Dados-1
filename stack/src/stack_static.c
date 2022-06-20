#include "stack_static.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct _static_stack{
    int *data;
    long capaity;
    long top;
} StaticStack;

StaticStack *StaticStack_create(long capacity){
    StaticStack *S= calloc(1, sizeof(StaticStack));
    S->capaity= capacity;
    S->top=-1;
    S->data= (int*) calloc(S->capaity, sizeof(int));
    
    return S;
}

void StaticStack_destroy(StaticStack **S_ref){
    StaticStack *S= *S_ref;
    free(S->data);
    free(S);
    S_ref= NULL;
}
bool StaticStack_is_empty(const StaticStack *S){
    return S->top == -1;
}
bool StaticStack_is_full(const StaticStack *S){
    return S->top == (S->capaity -1);
}
//vai inserir um novo elemento no topo da pilha
void StaticStack_push(StaticStack *S, int val){
    //caso a pilha ja esteja cheia por ser tratar de uma pilha estatica 
    if(StaticStack_is_full(S)){
        fprintf(stderr, "A pilha estar cheia\n");
        exit(EXIT_FAILURE); //TERMINA O PROGRAMA
    }

    S->data[S->top++]= val;
}
//retorna o valor do topo da pilha
int StaticStack_peek(const StaticStack *S){
    if(StaticStack_is_empty(S)){
        fprintf(stderr, "A pilha estar vazia\n");
        exit(EXIT_FAILURE); //TERMINA O PROGRAMA
    }
    return S->data[S->top];
}
//retorna o topo da pilha e desenpilha 
int StaticStack_pop(StaticStack *S){
    if(StaticStack_is_empty(S)){
        fprintf(stderr, "A pilha estar vazia\n");
        exit(EXIT_FAILURE); //TERMINA O PROGRAMA
    }
    int val = S->data[S->top];
    S->top--;
    return val;
}
//imprime a pilha
void StaticStack_print(const StaticStack *S){
    printf("Capacity:   %ld\n", S->capaity);
    printf("Top: %ld\n", S->top);

    for(long i = 0; i < S->top; i++){
        printf("%d, ", S->data[i]);
    }
    puts("");
}
