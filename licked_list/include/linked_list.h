#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _snote SNote;
typedef struct _linked_list LinkedList;


SNote *SNote_create(int val);
LinkedList *LinkedList_create();
void LinkediList_destroy(LinkedList **L_ref);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);
void LinkedList_remove_p(LinkedList *L, int val);
void LinkedList_remove(LinkedList *L, int val);
int LinkedList_size(const LinkedList *L);
int LinkedList_size_slow(const LinkedList *L);
int LinkedList_first_val(const LinkedList *L);
int LinkedList_last_val(const LinkedList *L);
int LinkedList_get_val(const LinkedList *L, int index);

#endif