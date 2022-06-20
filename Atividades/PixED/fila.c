#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
//estrutura do pix
typedef struct typePix{
	int id_orig, id_dest;
	float valor;
	Pix *next;
} Pix;
//controladores
typedef struct typeQueue{
	Pix *end;
	int qty, MAX;
}Fila;
//cria um novo nó da fila
Pix* Pix_create(void){
	Pix *novo=calloc(1,sizeof(Pix));
	if(novo==NULL) return 0;

	scanf("%d%d%f", &novo->id_orig, &novo->id_dest, &novo->valor);
    //verifica se os dadados são validos
	if(novo->id_orig==0 && novo->id_dest==0)
		return 0;
	else{
		novo->next=novo;
		return novo;
	}
}
//cria um fila 
Fila* Fila_create(void){
	Fila *nova=calloc(1,sizeof(Fila));
	if(!nova) return 0;

	nova->end=NULL;
    nova->MAX=0;
	nova->qty=0;
	return nova;
}
//adiciona um novo nó na fila 
int Fila_enqueue(Fila *fila){
	Pix *new=Pix_create();
	if(new==NULL) return 0;
    //se a lista estiver vazia
	if(fila->end==NULL){
		fila->end=new;
    }
	else{
        //incerção no final da fila
		new->next=fila->end->next;
        //antigo final da fila vai aponta para o novo final 
		fila->end->next=new;
        //corrigindo o encademento o controlador vai aponta para o novo final da fila
		fila->end=new;
	}
    fila->qty++;
	return 1;
}
//remove a cabeça da fila
int Fila_dequeue(Fila *fila, Pix *temp){
    //verifica se a lista passada e valida
	if(isEmpty(fila)) return 0;
    
	Pix *oldHead=fila->end->next;
	*temp=*oldHead;
	fila->end->next=oldHead->next;
	free(oldHead);
	fila->qty--;
	if(fila->qty==0)
		fila->end=NULL;
	return 1;
}

int Fila_destroy(Fila *fila){
	if(!isEmpty(fila)){
		Pix *head=fila->end->next;
		while(head!=fila->end && head){
			fila->end->next=head->next;
			free(head);
			head=fila->end->next;
		}
		free(fila->end);
	}
	free(fila);
	return 1;
}
//verifica se a fila estar vazia
int isEmpty(Fila *fila){
	return fila->end==NULL;
}
//vai pegar o tamanho da fila
int size(Fila *fila){
    scanf("%d", &fila->MAX);
    if(fila->MAX<=0){
        return 0;
    }else{
        return 1;
    }
}
//vai fazer o processo do pix
int pix(Fila *fila){
    Pix info;
    while (Fila_enqueue(fila)){
        if(fila->qty==fila->MAX){
			while(Fila_dequeue(fila, &info))
				printf("(%d, %d, %.2f),", info.id_orig, info.id_dest, info.valor);
		}
    }
    if(fila->qty>0){
		while(Fila_dequeue(fila, &info))
			printf("(%d, %d, %.2f),", info.id_orig, info.id_dest, info.valor);
		putchar('\n');
	}
    return 1;
}