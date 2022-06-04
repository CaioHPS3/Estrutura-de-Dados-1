#include<stdio.h>
#include "LDouble.h"

int main(){

  char buffer[4097];
  scanf("%4096s", buffer);
  TDList* num1 = TDList_generate(buffer);
  scanf("%4096s", buffer);
  TDList* num2 = TDList_generate(buffer);
  TDList* sum = TDList_sum(num1, num2);
  TDList_print(sum);
  TDList_destroy(&num1);
  TDList_destroy(&num2);
  TDList_destroy(&sum); 
  return 0;

}
