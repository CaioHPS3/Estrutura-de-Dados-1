#ifndef FILA_H
#define FILA_H

typedef struct typeQueue Fila;
typedef struct typePix Pix;

Fila* Fila_create(void);
int Fila_enqueue(Fila *);
int Fila_dequeue(Fila *, Pix *);
int size(Fila *);
int pix(Fila *);
int Fila_destroy(Fila *);
int isEmpty(Fila *);
#endif