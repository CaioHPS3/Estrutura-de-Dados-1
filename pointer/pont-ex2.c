#include <stdio.h>

void swap(int *x, int *y){
    int aux;
    aux= *x;
    *x = *y;
    *y = aux;

}

int main(){
    int a, b;
    a=59; b=33;
    printf("valor de a %d, valor de b %d\n\n", a , b);
    swap(&a, &b);
    printf("valor de a %d, valor de b %d\n\n", a , b);
        
   return 0;
}