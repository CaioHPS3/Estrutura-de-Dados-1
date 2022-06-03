#include <stdio.h>

int soma(int *x, int *y, int *z){
    int soma;
    soma=*x+*y+*z;
    return soma;
}
int multipli(int *x, int *y, int *z){
    int mult;
    mult=(*x)*(*y)*(*z);
    return mult;
}
int sub(int *x, int *y, int *z){
    int subi;
    subi=*x-*y-*z;
    return subi;
}
int div(int *x, int *y, int *z){
    int divi;
    divi=((*x)/(*y))/(*z);
    return divi;
}
int med(int *x, int *y, int *z){
    int media, med;
    med=soma(x, y, z);
    media=med/3;
    return media;

}
int coleta(int *x, int *y, int *z){
    puts("Qual vai ser o valor de a");
    scanf("%d", x);
    puts("Qual vai ser o valor de b");
    scanf("%d", y);
    puts("Qual vai ser o valor de c");
    scanf("%d", z);

}
int main(){
    int a, b, c;
    char op[10], op2[5];
    do{
        coleta(&a, &b, &c);
    do{

        puts("Qual operação vc deseja fazer ?");
    scanf("%s", op);
    switch (op[2]){
    case 'm':
        printf("A soma eh %d\n", soma(&a, &b, &c));
        break;
    case 'v':
        printf("A diviçao eh %d\n", div(&a, &b, &c));
        break;
    case 'l':
        printf("A multiplicasão eh %d\n", multipli(&a, &b, &c));
        break;
    case 'b':
        printf("A subtração eh %d\n", sub(&a, &b, &c));
        break;
    case 'd':
        printf("A media eh %d\n", med(&a, &b, &c));
        break;

    default:
        break;
    }
    puts("Deseja fazer outra operação ?");
    scanf("%s", op2);

    } while(op2[0]!='n');
    
    puts("Deseja fazer outra operação com outros numeros ?");
    scanf("%s", op2);

    }while(op2[0]=='s');
    
    return 0;

}