#include <stdio.h>

int main(){
    int a, b, c;
    a=10

    printf("O &a = %d o valor de a = %d", &a, a);
    printf("O &b = %d o valor de b = %d", &b, b);
    printf("O &c = %d o valor de c = %d", &c, c);
    b=a*2;
    c=a+b;
    printf("O &a = %d o valor de a = %d", &a, a);
    printf("O &b = %d o valor de b = %d", &b, b);
    printf("O &c = %d o valor de c = %d", &c, c);
        return 0;
}