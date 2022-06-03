//implementação
#include "exer.h"
#include <stdio.h>

float create(int nume, int deno){
    return ((float)nume/deno);
}
float sum(float num1, float num2){
    return ((float)num1+num2);
}
float mutiplica(float num1, float num2){
    return ((float)num1*num2);
}
void test(float num1, float num2){
    if(num1==num2){
        printf("Os numeros sao iguais\n");
    }else{
        printf("nao sao iguais\n");
    }
}



