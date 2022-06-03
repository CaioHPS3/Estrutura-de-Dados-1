#include <stdio.h>
#include <stdlib.h>
float **aloca(size_t nrows, size_t ncols){
    float **m;
    m=(float**)calloc(nrows,sizeof(float*));
    for(int a=0; a<3; a++){
        m[a]=(float*)calloc(ncols,sizeof(float));
    }
    return m;
    /*
        função que serve para alocar dinamicamente memoria na memoria heap no caso uma matriz
        primeiro criar um ponteiro de ponteiro **m que pode receber o endereço de um ponteiros que estaram na heap
        logo depois usando calloc irar receber a quantidade de ponteiros desejadas "vindo um vetor de ponteiros"
        que guarda endereços vendo esses endereços as linhas da matriz dinamicas, depois criar um laço de repetição
        para usar o vetor de endereços m para alocar a quantidades de colunas da matriz sendo as colunas onde vai ficar
        os valores de fato sendo alocado um tipo primitivo ex: int, float, double etc. (A alocação vem descendo os asteristicos
        sendo o primeiro ponteiro de ponteiro **m que armazena o endereços de ponteiros *m[a] que recebem o endereço dos tipos
        primitivos).
    */
}
float preenche(float **x, int nl, int nc){
    int a, b;
    for(a=0;a<nl;a++){
        for(b=0;b<nc;b++){
            printf("Qual vai ser o valor da linha %d coluna %d\n", a, b);
            // o conteudo de x (*x) = primeira linha da matriz vai andar coluna pro coluna "b"
            scanf("%f", (*x+b));

        }
        // x++ pula para a proxima linha
        x++;
    }
}
void imprime(float **y, int nl, int nc){
    int a, b;
    for(a=0;a<nl;a++){
        printf("\nO endereço da linha %d eh %p\n", a, &y[a]);
        for(b=0;b<nc;b++){
            printf("Qual vai ser o valor da Matriz[%d][%d]= %.2f\n", a, b, y[a][b]);
            printf("O endereço Matriz[%d][%d]= %p\n", a, b, &y[a][b]);
        }
        puts("");
    }    

}
void desaloca(float ***w){
    float **aux;
    for(int a=0;a<3;a++){ 
        free(aux[a]);
    }
    free(aux);
    *w=NULL;
}

/*
    A função main irar recer parametros de fora do usuario pelo terminal
    sendo o argc  o contador da quantidade de argumentos que estão entrando
    sendo a chamada a função contada, o argv e um vetor de strings que vai
    vai armazenar o que foi digitado no formato de strings. **argv==*argv[]. 
*/


int main(int argc, char **argv){
    if(argc!=3){
        printf("\nERRO\n Esperace o numero de linhas e de colunas\n");
        exit(-1);
    }
    // atoi(); função que pegar uma strings e transforma em um  int.
    int nrows = atoi(argv[1]);
    int ncols = atoi(argv[2]);
     printf("Os numeros são nrows = %d  e ncols = %d\n", nrows, ncols);    
    float **matriz;
    matriz = aloca(nrows, ncols);
    preenche(matriz, nrows, ncols);
    imprime(matriz, nrows, ncols);
    desaloca(&matriz);
    printf("\nMatriz is NULL %d\n?", matriz==NULL);

}