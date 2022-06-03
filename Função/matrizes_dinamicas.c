#include <stdio.h>
#include <stdlib.h>


int main(){
    int **p; 
    // criando um ponteiro de ponteiro para a criação da matriz dinamica
    p=(int**)calloc(2,sizeof(int*));
    // p recebendo o endereço de dois ponteiros para inteiros que estão na    
    // memoria dinamica que coresponde ao numero de linhas
    for(int a=0;a<2;a++){
        p[a]=(int*)calloc(3,sizeof(int));
        /* criando um laço de repetição do tamanho do numero de linhas da matriz
        onde o endereço das linha que são ponteiros para inteiro vão receber a alocação de
        memoria do tamanho int na quantidade do numero de colunas p[2][3] duas linhas e tres colunas 
        */
    }
    for(int l=0;l<2;l++){
        for(int c=0;c<3;c++){
            printf("Vamos prencher a Matriz[%d][%d]\n", l+1, c+1);
            scanf("%d", p[l][c]);
            // preenchendo a matriz usando usando l e c p[l][c]
        }
    }
    puts("");
    for(int l=0;l<2;l++){
        for(int c=0;c<3;c++){
            printf("Matriz[%d][%d]= %d\n", l+1, c+1, p[l][c]);
            
        }
    }
    for(int l=0;l<2;l++){
        free(p[l]);
    }
    free(p);
    p=NULL;
    // desaloca a matriz de dentro para fora


}