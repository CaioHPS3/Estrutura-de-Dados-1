#include "LDouble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//nó
struct no{
  int info;
  struct no *prox, *ant;
};
//cabeça da lista
struct double_linked{
  struct no *inicio;
  struct no *fim;
};

// cria um novo nó para lista
TNo* TNo_createnfill(int val){
  TNo* novo = calloc(1,sizeof(TNo));
  if(novo){
    novo->info = val;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  return novo;
}
//cria a cabeça da lista
TDList* TDList_create(){
  TDList* nova = calloc(1,sizeof(TDList));
  if(nova){
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}
// vai imprime de traz para frente
void TDList_print(TDList* list){
  if(list){
    // o ponteiro aux aponta para o final da lista
    TNo* aux = list->fim;
    //equanto aux diferente de NULL
    while(aux){
      printf("%d", aux->info);
      //aux vai apota para o nó onde ant(o ponteiro ANTERIOR ao nó atual) estar apotando
      aux = aux->ant;
    }
    puts("");
  }
}
//vai inseri um valor em um nó no final da lista
int insert_node(TDList* list, int val){

	TNo* new_node=TNo_createnfill(val);
  // se a lista estiver vazia
	if(list->inicio==NULL){
		list->inicio=new_node;
		list->fim=new_node;
	}
  //se a lista ja tiver algum elemento
  else{
    // novo nó vai aponta para onde o fim da lista estar apontando
    // o antigo fim da lista 
		new_node->ant=list->fim;
    //o nó do "fim" da lista, seu proteiro prox vai aponta para o novo nó
		list->fim->prox=new_node;
    //e o ponteiro fim vai aponta para o novo nó (que é o novo fim da lista)
    //corrigindo o encadeamento 
		list->fim=new_node;
	} return 1;
}
//vai criar uma nova lista, transforma o vetor de caracteres em int
TDList* TDList_generate(char* charNum){
  TDList *nova = TDList_create();
  //strlen vai conta qual o tamanho(strlen) do vetor char 
  int i=0, size= strlen(charNum);
  while(i<size){
    //chamado a função de cria um nó e passando o lista 
    //e o valor transformando o char em um int (-48 com se tivesse tirando a parte char tabela aciir)
    insert_node(nova, charNum[i]-48);
    i++;
  }
  return nova;
}
// vai fazer a soma das lista criando uma nova lista
TDList* TDList_sum(TDList* list1, TDList* list2){
  TDList* sum=TDList_create();
	int sobra=0;
// soma normal do rabo(final) ate a cabeça
	TNo* aux1=list1->fim;
	TNo* aux2=list2->fim;
  //enquanto nem uma das lista chegar no final(soma par a par)
	while(aux1!=NULL || aux2!=NULL){
    // se nem umas das lista estiver chegado os final
		if(aux1!=NULL && aux2!=NULL){
      //vai ser criado um novo nó como a soma da sobra com a soma das informações
      // da lista 1 e 2  
			insert_node(sum, sobra+(aux1->info+aux2->info)%10);
      //pegando a sobra da soma se houver
			sobra=(sobra+aux1->info+aux2->info)/10;
      //os auxliares vão aponta para o anteior a ele
			aux1=aux1->ant;
			aux2=aux2->ant;
		}//se restar numero para serem somados em alguma das outras listas
    //caso alguma lista seja maior que a outra
    else{
			if(aux1!=NULL){
				insert_node(sum, sobra+(aux1->info)%10);
				sobra=(sobra+aux1->info)/10;
				aux1=aux1->ant;
			}else{
				insert_node(sum, sobra+(aux2->info)%10);
				sobra=(sobra+aux2->info)/10;
				aux2=aux2->ant;
			}
		}
	}
	if(sobra>0)
		insert_node(sum, sobra);
	return sum;
}
//desaloca os nós e as lista
void TDList_destroy(TDList** L_ref){
  TDList *L = *L_ref;

    TNo *p = L->inicio;
    TNo *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}
