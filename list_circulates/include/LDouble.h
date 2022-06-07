#ifndef DUPLAMENTE_LISTA
#define DUPLAMENTE_LISTA

typedef struct double_linked TDList;
typedef struct no TNo;

/**
* A função TDList_create() eh responsavel por alocar espaco na memoria e preencher inicialmente os 
* ponteiros do no descritor da lista. Uma vez alocada e inicializada, a lista eh retornada (o 
valor do endereco para a qual foi alocada)
* */
TDList* TDList_create();
/**
* A funcao TDList_destroy eh responsavel por receber um ponteiro valido para uma lista alocada e navegar
* por cada no e ir seguidamente deletando-os da memoria. Veja que deletar apoenas o ponteiro inicio da 
* lista eh insuficiente.
* @param TDList* o ponteiro para o no descritor que foi alocado previamente.
* */
void TDList_destroy(TDList**);

/**
 * Gera uma lista a partir de uma string de numeros.
 * Retorna uma lista duplamente encadeada representando a sequencia. 
 * DICA 1: Cuidado que cada caractere eh diferente do numero inteiro que representa.
 * DICA 2: O numero estarah indexado de 0 a strlen()-1, sendo a casa 0 o digito mais significativo.
 * DICA 3: Voce pode criar a funcao de insercao para inserir no inicio ou fim conforme vc achar necessario.
 * @return: TDList*
 * @param: char* o numero como uma cadeia de caracteres. Ex.: "1234567897987987"
 * */
TDList* TDList_generate(char*);
/**
 * Toma duas listas duplamente como parametro, representando inteiros gigantes e gera uma terceira lista
 * sendo um outro numero possivelmente gigante representando a soma. 
 * DICA: Lembre-se de passar o carry para as próximas casas. Voce pode comecar do fim e avancar usando o ponteiro ant.
 * @param: ponteiros para listas duplamente encadeada representando dois numeros inteiros positivos possivelmente gigantes.
 * @return: retorna o ponteiro para uma lista duplamente encadeada representando outro numero possivelmente gigante 
 * (resultado da soma dos dois numeros de parametro)
 * */
TDList* TDList_sum(TDList*, TDList*);
/**
 * Imprime a lista duplamente encadeada como sendo um numero inteiro gigante.
 * Os numeros deverao ser impressos um ao lado do outro sem espaco e com um \n no final da lista.
 * @param: ponteiro para lista duplamente encadeada que representa um numero inteiro positivo.
 */
void TDList_print(TDList*);


#endif
