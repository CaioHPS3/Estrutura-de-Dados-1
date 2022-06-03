#include <stdio.h>

int main(){
    int a, b, *p1, *p2;
    a=4;
    b=3;
    p1=&a;
    p2=p1;
    *p2 = *p1 + 3;
    b= b * (*p1);
    (*p2)++;
    p1=&b;
    printf("valor de p1 %d, valor de p2 %d\n", *p1, *p2);
    printf("valor de a %d, valor de b %d\n", a, b);


}