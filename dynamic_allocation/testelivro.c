#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _lirro{
  char titulo[100];
  unsigned int num_pag;
  float preco;

}Livro;
typedef struct _aluno{
  char nome[50];
  int idade;
  Livro *livro_fav;
    
}Aluno;
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
Aluno *cria_alunos(const char *nome, int idade, Livro *livro){
    //dados recebidos por refenrencia logo é criado um local na memoria para armazenalos
    Aluno *aluno=(Aluno*)calloc(1,sizeof(Aluno));
    //colocando os dados que sejam ser alocados
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    //irar armazenar um copia do livro
    aluno->livro_fav = copialivro(livro);
    //retorna o endereço de onde os dados recebidos foram guardados
    return aluno;

}
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
void imprime_aluno(Aluno *aluno){
  printf("O nome do aluno eh = %s\n",aluno->nome);
  printf("O a idade do aluno eh = %d\n", aluno->idade);
  puts("O livro favorito");
  imprime_livro(aluno->livro_fav);
}
void destroi_aluno(Aluno **alunoR){
  Aluno *aluno = *alunoR;
  destroi_livro(&aluno->livro_fav);
  free(aluno);
  *alunoR=NULL;

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
  char nomes[40];
  Aluno caio;
  /*
    nomeia as os tipos que estão dentro da struct  
  */
  strcpy(caio.nome, "Caio Henrique Pinho Santos");
  caio.idade = 20;
  
  // ou
  //Aluno caio={.nome = "Caio Henrique Pinho Santos", .idade = 20};
  /*
  printf("Sizeof(Aluno)= %lu bytes\n", sizeof(Aluno));
  // Alocação dinamica dos tipos que estão na struct
  Aluno *caioh=(Aluno*)calloc(1, sizeof(Aluno));
  //Para acessar os campos da struct por meio do ponteiro usamos ->
  strcpy(caioh->nome, "Caio Henrique Pinho Santos");
  caioh->idade = 20;
  */

  Livro *livro1=create_livro("Senhor do Aneis", 341, 58.52);
  imprime_livro(livro1);
  Aluno *kaio = cria_alunos("Kaio Henrique", 20, livro1);
  imprime_aluno(kaio);
  puts("-----------");
  printf("O livro que o Kaio Gosta é o Senhor do Aneis  ?\n");
  if(livro_igual(kaio->livro_fav, livro1)==1){
      printf("Sim\n");
  }else{
    printf("Nao\n");
  }
  
  destroi_livro(&livro1);
  destroi_aluno(&kaio);
  
  printf("livro1 == NULL ? %d\n", livro1==NULL);
   printf("Kaio  == NULL ? %d\n", kaio==NULL);

  return 0;
}