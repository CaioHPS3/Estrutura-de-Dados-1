#include "lista_estatica.h"
#include <stdio.h>

int main(){
    Lista *li;
    li=cria_lista();

    printf("%p", li);
    puts("");

    destroi(li);
    
    return 0;
}
