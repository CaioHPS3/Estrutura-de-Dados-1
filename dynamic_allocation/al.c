#include <stdio.h>
#include <stdlib.h>

int main(){

    int n[5]={0, 1, 50, 3, 4};
    int *v2, *p, i;
    for(int a=0;a<5;a++){
        printf("O numero eh %d\n", n[a]);
    }
    p=n;
    p[3]= p[4]=10;
    puts("");
    for(int a=0;a<5;a++){
        printf("O numero eh %d\n", n[a]);
    }
    v2 =(int*)calloc(5,sizeof(int));

    for(int a=0;a<5;a++){
        v2[a]=p[a];
    }
    puts("V2");

    for(int a=0;a<5;a++){
        printf("O numero eh %d\n", v2[a]);
    }
    free(v2);
    v2=NULL;

}