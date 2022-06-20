#include "fila.h"
#include <stdio.h>

int main(void){
	Fila *filap;
    filap=Fila_create();
    size(filap);
    pix(filap);
    Fila_destroy(filap);
	return 0;
}