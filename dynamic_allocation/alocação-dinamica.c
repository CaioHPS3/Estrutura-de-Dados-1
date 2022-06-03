#include <stdio.h>
#include <stdlib.h>

void dados(int *x, int *y, char **z){
    
    for(int a=0;a<5;a++){
        printf("Qual o nome da pessoal %d ?\n", a+1);
        scanf("%s", z[a]);    
    }
    
    
    for(int a=0; a<5;a++){
        printf("Qual a idade e ano de nascismento do(a) %s ?\n", z[a]);
        scanf("%d", &x[a]);
        printf("Qual o ano de nascimento da pessoa %s ?\n", z[a]);
        scanf("%d", &y[a]);
    }

}
void desaloca(int **a){
    free(*a);
    *a=NULL;
}
void desalocaChar(char ***b){
    for(int a=0;a<5;a++){
        free(**b[a]);
        **b=NULL;
    }
    free(*b);
    *b=NULL;
}

int main(){
    int c[5] = {10, 20, 30, 40, 50};

    //puts("VETOR ESTATICO");

    //printf("&c = %p, c = %p\n", &c, c);

    //for(int a=0;a<5;a++){
    
         //printf("&c[%d]= %p, c[%d]= %d\n", a, &c[a], a, c[a]);
    
    //}
    //puts("VETOR Dinamico Malloc");

    int *idad=(int*)malloc(5*sizeof(int));

    //printf("&m = %p, m = %p\n", &m, m);
    //
    
//
    //for(int a=0;a<5;a++){
    //    
    //    printf("&m[%d]= %p, *m[%d]= %d\n", a, &m[a], a, m[a]);
    //
    //}
    //puts("\nVETOR DINAMICO CALLOC\n");

    int *ano=(int*)calloc(5,sizeof(int));

    //printf("&ca = %p, ca = %p\n", &ca, ca);
    //
    //for(int a=0;a<5;a++){
    //    
    //    printf("&ca[%d]= %p, *ca[%d]= %d\n", a, &ca[a], a, ca[a]);
    //
    //}
    char **nomes=(char**) calloc(5,sizeof(char*));//?? falta aruma 
    for(int a=0;a<5;a++){
        nomes[a]=(char*)calloc(25,sizeof(char));
    }
    //printf("&nomes =%p nome =%p\n", &nomes, nomes);
    //for(int a=0;a<5;a++){
    //    printf("&nomes[%d]= %p, nomes[%d]= %p\n",  a+1, &nomes[a], a+1, nomes[a]);
    //}
    dados(idad, ano, nomes);
    for(int a=0;a<5;a++){
        printf("A pessoa %s tem %d e nasceu em %d\n", nomes[a], idad[a], ano[a]);
    }
    
return 0;
}