#include <stdio.h>

int main(){
    int a=10;
    int *p1=&a;
    int **p2=&p1;   
    
    printf("&a= %p, a= %d\n", &a, a);
    printf("&p1= %p, p1= %p, *p1= %d\n", &p1, p1, *p1);
    printf("&p2= %p, p2= %p, *p2= %d\n", &p2, p2, **p2);
    
    **p2=100;

    printf("&a= %p, a= %d\n", &a, a);
    printf("&p1= %p, p1= %p, *p1= %d\n", &p1, p1, *p1);
    printf("&p2= %p, p2= %p, *p2= %p, **p2= %d\n", &p2, p2, *p2, **p2);

    puts("Deu certo ?");
    return 0;


}