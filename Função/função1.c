#include <stdio.h>

void coleta(int *x, int *y){
    puts("Qual o valor para a");
    scanf("%d", x);
    puts("Qual o valor para b");
    scanf("%d", y);
}
void modifica(int *x, int *y){
    x = y;
    *y= (*y) *(*x);
    *x= *x + 2;

}
void fnomes(char x[5][20]){
   int a, b;
   //coleta(&a, &b);
   //modifica(&a, &b);
   //printf("Valor de A %d, valor de B %d\n", a, b);
    for(a=0;a<5;a++){
        printf("Qual o nome do aluno %d\n",a+1);
        scanf("%s", x[a]);
    }
}

int main(){
    int a;
    char nomes[5][20]={""};
    fnomes(nomes);
    for(a=0;a<5;a++){

        printf("O nome do aluno eh %s\n", nomes[a]);
    }

    return 0;
}