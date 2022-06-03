// especificação
#define MAX 100

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista *cria_lista();
void destroi(Lista*);
int tamanho_list(Lista*);
int tamanho_cheia(Lista*);
int tamanho_vazia(Lista*);
int insere_lista_final(Lista * li, struct aluno val);
int insere_lista_inicio(Lista * li, struct aluno val);
int insere_lista_ordenada(Lista * li, struct aluno val);
int remove_list_final(Lista* li);
int remove_list_incio(Lista* li);
int remove_list(Lista *li, int mat);