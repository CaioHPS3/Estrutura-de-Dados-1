#ifndef STATIC_LIST_H
#define STATIC_LIST_H

typedef struct static_list TStaticList;

TStaticList* TStaticList_create();
int TStaticList_insert(int input, TStaticList* lista);
void TStaticList_print(TStaticList* lista);
void TStaticList_destroy(TStaticList* *lista);
int TStaticList_remove(int val, TStaticList* lista);
int TStaticlist_concatenar(TStaticList* lista1, TStaticList* lista2);


#endif