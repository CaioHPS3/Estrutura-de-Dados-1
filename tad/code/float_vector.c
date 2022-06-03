
// implementação .c (Como vai ser feito)

#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/************************* Interface privada **************************************/
/*  As função aqui dentro não estaram disponivel para o usuario
    So estara disponivel as função que estão no .h
    Vc pode declarar funções aqui para usar no seu algarismo, sem precisar declarar nas especificação .h 
*/
struct float_vector {
    int capacity; // numero maximo de elementos
    int size; // Quant de elementos armazenados
    float *data; // vetor de float
};
//função que não foi especificada no .h, mas estar sendo usada no facilta a implementação de outras funções
bool isFull(const FloatVector *vec){
    return vec->size == vec->capacity;
}
/**********************************************************************************/
/************************* Implementação da Interface publica **************************************/
/*                       funções que o usario vai ter acesso para poder usar                     */

/**
 * @brief cria (aloca) um vetor de floats com uma dada capacidade
 * 
 * @param capacity Capacidade do vetor.
 * @return FloatVector*  Um vetor de floats alocado/criado.
 */


// cria um struct
FloatVector *create(int capacity){
    
    FloatVector *vec =(FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size= 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));

    return vec;
}
// destroi um struct criada
void destroy(FloatVector **vec_ref){
    FloatVector *vec = *vec_ref;
    free(vec->data);
    free(vec);
    *vec_ref=NULL;
}
// adiciona um valor no vetor da struct 
void append(FloatVector *vec, float val){
    // se a quantidade de elemento for igual a capacidade do vetor vai imprimir uma mensagem de erro
    if(isFull(vec)){
        //vai imprimir na tela com um formato de erro
        fprintf(stderr, "Erro in append\n");
        fprintf(stderr, "Vector is full");
        //vai mata o programa como se tivesse ocorrido um erro
        exit(EXIT_FAILURE);
    }
    //vai armazena o valor recebido "val", no vetor date na posição size, que começa em zero e vai recebendo 1
    // a cada vez que um valor e adcionado
    vec->data[vec->size]= val;
    //size vai constar mais um elemento 
    vec->size++;
}
//Imprime os elementos do vetor
void print(const FloatVector *vec){
    puts("------------");
    printf("the size = %d \n", vec->size);
    printf("the capacity = %d\n", vec->capacity);
    puts("----------");
    for(int i=0; i< vec->size; i++){
        printf("the value [%d] = %.2f\n", i, vec->data[i]);
        puts("------------");
    }
}
// mostra quantos elementos tem no vetor
int size(const FloatVector *vec){
    return vec->size;
}
//mostra a capacidade do vetor
int capacity(const FloatVector *vec){
    return vec->capacity;
}
//dado certo indicer o a função vai buscar o valor que estar na posição desejada no vetor
float at(const FloatVector *vec, int index){
    //verificação para ver se a posição que quer saber existe ou estar disponivel
    if(index<0||index>=vec->size){
        fprintf(stderr, "ERRO in at");
        // "O indice estar fora do limite"
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}
// faz a mesma coisa do codigo de cima so que mais rapido e sem a verificação
float get(const FloatVector *vec, int index){
    return vec->data[index];
}
// armazena o val no vetor da posição index e lança um erro se o indecer for invalido
void set(FloatVector *vec, int index, float val){
    if(index<0||index>=vec->size){
        fprintf(stderr, "ERRO in at");
        // "O indice estar fora do limite"
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }
    vec->data[index]=val;
}