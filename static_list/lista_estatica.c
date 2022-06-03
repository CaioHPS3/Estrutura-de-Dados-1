#include "lista_estatica.h"
#include  <stdlib.h>

struct lista
{
    //vetor lista vai conter a quantidade de elementos da lista
    //e um ponteiro para a struct aluno
    int quant;
    struct aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li;
    //vai alocar um vetor lista em li
    li = calloc(1,sizeof(Lista));
    //verifica se foi a memoria foi alocada direito
    if(li!=NULL){
        return 0;
    }

    //vai apontar para o local disponivel na lista
    li->quant=0;
    return li;
}
void destroi(Lista *li){
    free(li);
}
int tamanho_list(Lista* li){
    return li->quant;
}
int tamanho_cheia(Lista* li){
    return li->quant==MAX;

}
int tamanho_vazia(Lista* li){
    return li->quant==0;   
}
//insere um elemento no ultimo espaço dp vetor
int insere_lista_final(Lista * li, struct aluno val){
    if(tamanho_cheia(li)){
        return 0;
    }else{
        li->dados[li->quant]= val;
        li->quant++;
        return 1;
    }
}
//insere um elemento no primeiro espaço do vetor
int insere_lista_inicio(Lista * li, struct aluno val){
    if(tamanho_cheia(li)){
        return 0;
    }
    //joga todos os elementos uma casa a frente da sua para iniserir um elemento no primeiro espaço "0"
    // modificando as posições da ultima ate a primeira
    for(int i=li->quant-1; i>=0; i--){
        li->dados[i+1] = li->dados[i];
     }
    //colocando o vaor desejado no primeiro indicer do vetor
    li->dados[0]=val;
    li->quant++;
    return 1;
}
int insere_lista_ordenada(Lista * li, struct aluno val){
    if(tamanho_cheia(li)){
        return 0;
    }
    int i,k =0;
    /*  
        (vai percorrer a lista ate onde tiver elementos) 
        E (&&)
        vai verificar a struct aluno pelo numero das matricula dos aluno que ja estar na lista 
        e ver se é menor que a do novo aluno que queremos colocar
        ex: queremos colocar um novo aluno que o numero de matrucula 16
        dados=[10, 12, 19, 20, 25]
        (o while vai tercorer o vetor com as duas condições)
        a sengunda condição vai identificar que 12 e menor que 16
        então vai sair do lupe e vai entrar no for que vai relaocar os valores
        para liberar a posição que estar depois do 12 para a entrada do 16 
    */
    while(i<li->quant && li->dados[i].matricula < val.matricula){
        i++;
    }
    for(k=li->quant-1; k>=i; k--){
        li->dados[k+1]= li->dados[k];
    }
    li->dados[i] = val;
    li->quant++;
    return 1;

}
//remove o ultimo item da lista
int remove_list_final(Lista* li){

    if(tamanho_vazia(li)){
        return 0;
    }
    //diminuir a quantidade em 1
    li->quant--;
    return 1;

}
//remove o primeiro item da lista
int remove_list_incio(Lista* li){
    if(tamanho_vazia(li)){
        return 0;
    }
    int k=0;
    //jogar os emententos uma casa para frente
    for(k=li->quant-1;k<li->quant-1; k++){
        li->dados[k]= li->dados[k+1];
    }
    //diminuir a quantidade em 1
    li->quant--;
    return 0;

}
//remove um elemneto da lista a sua escolha (mat)
int remove_list(Lista *li, int mat){
    if(tamanho_vazia(li)){
        return 0;
    }
    int i,k =0;
    /*
        O while tem duas condiçoes sendo a primeiro que vai percorrer o vetor ate onde tiver valores
        e a outras vai verificar se a matricula do aluno que quero remove (mat) estar na lista
        enquanto dados da matricula for diferente da matricula que quero remover o while
        vai continua rodando adicionando 1 em i 

    */
    while(i<li->quant && li->dados[i].matricula != mat){
        i++;
    }
    //se no lupe, i foi incrementado ate ficar maior que a quantidade de elementos
    // significa que a matricula que foi dada não estar no vetor
    // o programa é encerrado
    if(i==li->quant){
        return 0;
    }
    /*
        se o while não for satisfeiro (dados[i]==mat)
        então teremos a posição onde o elemento que desejo remover está
    */
    for(k=i; k<li->quant-1; k++){
        li->dados[k]= li->dados[k+1];
    }
    li->quant--;
    return 1;
}
