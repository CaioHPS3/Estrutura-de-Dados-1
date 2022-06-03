#include "exer2.h"
#include <stdio.h>

int main(){
    Conj *primeiro = create_conjunto(10);
    Conj *segundo = create_conjunto (5);

    include(primeiro, 1);
    include(primeiro, 2);
    include(primeiro, 3);
    include(primeiro, 4);
    include(primeiro, 5);
    include(primeiro, 6);
    include(primeiro, 7);
    include(primeiro, 8);
    include(primeiro, 9);
    include(primeiro, 10);
    include(segundo, 18);
    include(segundo, 5);
    include(segundo, 3);
    include(segundo, 11);
    include(segundo, 512);
    
    
    print(primeiro);
    print(segundo);
    puts("");
    Conj *terceiro=inter(primeiro, segundo);
    print(terceiro);


    desaloca(&primeiro);
    desaloca(&segundo);
    desaloca(&terceiro);

    return 0;
    
}