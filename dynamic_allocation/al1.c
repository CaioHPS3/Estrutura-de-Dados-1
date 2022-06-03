#include <stdio.h>
#include <stdlib.h>

double *aloca(){
    double *p;
    p=(double*)calloc(5,sizeof(double));
    printf("%p\n", p);

    return p;
}
void desaloca(double **v){
    free(*v);
    *v=NULL;
}
double alocareferencia(double **x){
    double *r;
    r=(double*)calloc(5,sizeof(double));
    *x=r;
}
double copia(double **x, double y[]){
    double *aux;
    aux=*x;
    for(int a=0;a<5;a++){
        y[a] = aux[a];
    }
}
int main(){
    printf("Olá mundo!\n");
    double *p2, vn[5];
    alocareferencia(&p2);
    p2[0]= 2.58963;
    for(int a=1;a<5;a++){
        p2[a]=p2[a-1] + 2.25266;
    }
    for(int a=0;a<5;a++){
        printf("O numero eh P2[%d] = %lf\n", a, p2[a]);
    }
    copia(&p2, vn);
    puts("");
    for(int a=0;a<5;a++){
        printf("O numero eh vm[%d] = %lf\n", a, vn[a]);
    }
    desaloca(&p2);
}