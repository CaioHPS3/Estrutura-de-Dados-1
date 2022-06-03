//implementação
#include "exer2.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct cojunto{
    int size;
    int capacity;
    int *vetor;
};
//verifica se o vetor estar cheio
bool isfull(Conj *vec){
    return vec->size==vec->capacity;
    //retornar verdadeiro se sim
}
//Cria um vetor vazio
Conj *create_conjunto(int capacity){
    Conj *vec=  calloc(1, sizeof(Conj));
    vec->size = 0;
    vec->capacity = capacity;
    vec->vetor= (int*) calloc(capacity, sizeof(int));
}
//desaloca um vetor
void desaloca(Conj **vec){
    Conj *aux= *vec;
    free(aux->vetor);
    free(aux);
    *vec=NULL;
}
//verifica se o valor que vai ser adicionado no vetor ja existe no vetor
int exist(Conj *vec, int val){
    for(int a=0; a < vec->capacity; a++){
        if(vec->vetor[a]==val){
            return 1;
            break;
        }
    }
    return 0;

}
// verifica se exite o valor recebido ja existe no vetor e retorna a posição do valor mo vetor
int existt(Conj *vec, int val){
    int size;
    for(int a=0; a < vec->capacity; a++){
        if(vec->vetor[a]==val){
            return a;
            break;
        }

    }
    return 0;

}
//Adiciona um valor no vetor
int include(Conj *vec, int val){
    if(isfull(vec)){
        printf("O vetor estar cheio\n");
        exit(EXIT_FAILURE);
    }
    if(exist(vec, val)==1){
        printf("O valor ja existe no vetor");
    }else{
    vec->vetor[vec->size]=val;
    vec->size++;
    }
}
// imprime o conjunto
int print(Conj *vec){

    printf("A capacidade do vetor e %d\n", vec->capacity);
    printf("A quantidade de elementos incluido e %d\n", vec->size);
    for(int a=0; a < vec->size; a++){
        printf("O elemento Vetor[%d] = %d\n", a+1, vec->vetor[a]);
    }
}
// realoca aloca o vetor fazendo os valores iguais a 0 sejam realocado para o final
// do vetor não estorando a memoria
int realoca(Conj *vec){
    int aux;
   for(int a=0; a< vec->capacity; a++){
       if(vec->vetor[a]==0 & (a+1 < vec->capacity)){
           aux= vec->vetor[a];
           vec->vetor[a]=vec->vetor[a+1];
           vec->vetor[a+1]=aux;
       }
   }
}
// e recebido um valor que é desejado tirar do vetor verifica se esse valor existe no vetor
// se existir iguala ele a 0 depois chama a função realoca para colocalo ele no final do vetor
int remov(Conj *vec, int val){
    if(existt(vec, val)!=0){
        vec->vetor[existt(vec, val)]=0;
        realoca(vec);
        vec->size--;
    }else{
        printf("O valor não existe no vetor");
    }
}
//pega dois conjuntos faz uma interseção para criar uma novo conjunto sem elementos repetidos
Conj *inter(Conj *vec1, Conj *vec2){
    int tamanho= vec1->capacity + vec2->capacity;
    Conj *novo= create_conjunto(tamanho);
    for(int a=0; a<vec1->capacity; a++){
        novo->vetor[a]=vec1->vetor[a];
        novo->size++;
    }
    for(int a=0; a< vec2->capacity; a++){
        if(exist(novo, vec2->vetor[a])==1){
            printf("\n");
        }else{
            novo->vetor[novo->size]=vec2->vetor[a];
            novo->size++;
        }
    }
    return novo;
}





