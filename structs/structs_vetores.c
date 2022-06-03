#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _lirro{
  char titulo[100];
  unsigned int num_pag;
  float preco;

}Livro;

//função de criação de um livro, irar receber os paramestros desejado
Livro *create_livro(char *titulo, int numerop, float preco){
  //apos se recebidos irar ser reservado um espaço na memoria
  Livro *livro=(Livro*)calloc(1, sizeof(Livro));
  //colocando os dados que seja ser colocado nas suas respectivas variaveis
  strcpy(livro->titulo, titulo);
  livro->num_pag = numerop;
  livro->preco = preco;
  //retornando o endereço de onde os dados foram armazenados
  return livro;
}
// faz uma copia do livro prefererido do aluno em outro endereço de memoria
Livro *copialivro(Livro *livro){
   
  return create_livro(livro->titulo, livro->num_pag, livro->preco);
}
//função que vai criar novos alunos
void imprime_livro(Livro *livro){
  printf("O titulo = %s\n", livro->titulo);
  printf("O numero de paginas = %d\n", livro->num_pag);
  printf("O preco do livro = %.2f\n", livro->preco);

}
void destroi_livro(Livro **livrod){
  Livro *livro= *livrod;
  free(livro);
  *livrod=NULL;
}

//função compara se dois livros são iguais acho que da patra usar com tudo
int livro_igual(const Livro *livro1, const Livro *livro2){
  //STRCMP e a função de fato, vc tem que passar dois argumentos
  //os quais vãio ser comparados e ser for verdade retornará 0
  if(strcmp(livro1->titulo, livro2->titulo)== 0){
    return 1;
  }else{
    return 0;
  }
}


int main(){

  Livro **vetor_livro=(Livro**)calloc(3,sizeof(Livro*));
  vetor_livro[0] =create_livro("Senhor do Aneis", 341, 58.52);
  vetor_livro[1] =create_livro("Fim da Proscrastinação", 150, 99.90);
  vetor_livro[2] =create_livro("Em Busca da felicidade", 250, 180);

  for(int a=0; a<3;a++){
    imprime_livro(vetor_livro[a]);
    puts("");
  }
  //destroi livro no vetor
  for(int a=0; a<3; a++){
    destroi_livro(&vetor_livro[a]);
  }
  free(vetor_livro);
  vetor_livro=NULL;

  return 0;
}