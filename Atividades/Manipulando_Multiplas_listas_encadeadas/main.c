#include <stdio.h>
#include "TStaticList.h"

int main(){
  TStaticList* lists[3] = {
    TStaticList_create(), 
    TStaticList_create(), 
    TStaticList_create()
  };
    char x; 
    int q=1; 
    int num; 
    int aux;

    while (q != 0)
    {
        scanf("%c", &x);
        if(x=='i'){
            scanf("%d", &num);
            scanf("%d", &aux);
            TStaticList_insert(num, lists[aux]);
        }
        if(x=='p'){
            scanf("%d", &num);
            scanf("%d", &aux);
            TStaticList_print(lists[aux]);
        }
        if(x=='q'){
            scanf("%d", &q);
        }
        if(x=='r'){
            scanf("%d", &num);
            scanf("%d", &aux);
            TStaticList_remove(num, lists[aux]);
        }
        if(x=='c'){
            scanf("%d", &aux);
            scanf("%d", &num);
            TStaticlist_concatenar(lists[aux], lists[num]);

        }
    }
    TStaticList_destroy(lists);
    
  return 0;
}
