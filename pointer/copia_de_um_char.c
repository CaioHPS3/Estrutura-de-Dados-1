#include <stdio.h>

void copiaa(char *s1, const char *s2){
    for (;(*s1=*s2)!='\0'; s1++, s2++){

    }
}
void copiaoo(char *s1, const char *s2){
    for(int i=0; (s1[i] = s2[i])!='\0'; i++){

    }
}

int main(){
    char copia[25], *origem = "A palvara a boa";
    char frase[]="Vamos testa tudo";
    copiaa(copia, origem);
    printf("A frase eh %s\n", copia);
    char copiao[25], *origem2 = "Pascoa eh legal";
    copiaoo(copiao, origem2);
    printf("A frase eh %s\n", copiao);
}