#include "TStaticList.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 5

struct static_list{
  int qty;
  int data[MAX];
};

int TStaticList_is_full(TStaticList* lista){
  return (lista->qty == MAX);
}
int TStaticList_is_NUUL(TStaticList* lista){
  return lista->qty==0;
}

TStaticList* TStaticList_create(){
  TStaticList* novo = malloc(sizeof(TStaticList));
  if(novo!=NULL){
    novo->qty = 0;
  }
  return novo;
}
int TStaticList_insert(int input, TStaticList* lista){
  if (TStaticList_is_full(lista)){
    printf("fail\n");
    return 0;
  }
  lista->data[lista->qty] = input;
  lista->qty++;
  printf("success\n");
  return 1;
}
void TStaticList_print(TStaticList* lista){
  for(int i=0; i<lista->qty; i++)
    printf("%d, ", lista->data[i]);
  putchar('\n');
}
void TStaticList_destroy(TStaticList* *lista){
  for(int a=0;a<3;a++){
    free(lista[a]);
  }
}
int TStaticList_remove(int val, TStaticList* lista){
  if(TStaticList_is_NUUL(lista)){
    printf("fail\n");
    return 0;
  }
  int i=0, k =0, a=0;
  while(i<lista->qty && lista->data[i]!=val){
    i++;
  }
  
  if(i==lista->qty){
    printf("not found\n");
    return 0;
  }
  for(k=i; k<lista->qty-1; k++){
        lista->data[k] = lista->data[k+1];
  }
  lista->qty--;
  printf("succes\n");
  
}
int TStaticlist_concatenar(TStaticList* lista1, TStaticList* lista2){
  if(lista1->qty+lista2->qty<=MAX){
    TStaticList *listaN = TStaticList_create();
    for(int a=0; a<lista1->qty;a++){
      listaN->data[listaN->qty]=lista1->data[a];
      listaN->qty++;
    }
    for(int a=0; a<lista2->qty;a++){
      listaN->data[listaN->qty]=lista2->data[a];
      listaN->qty++;
    }
    TStaticList_print(listaN);
    return 1;
  }else{
    printf("not possible\n");
    return 0;
  }
}
