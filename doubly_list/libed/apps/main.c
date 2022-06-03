#include<stdio.h>
#include "LDouble.h"

int main(){
  char buffer[4097];
  scanf("\n%4095s", buffer);
  TDList* num1 = TDList_generate(buffer);
  puts("");
  TDList_print(num1);
  scanf("\n%4095s", buffer);
  TDList* num2 = TDList_generate(buffer);
  puts("");
  TDList_print(num2);
  TDList* sum = TDList_sum(num1, num2);
  TDList_print(sum);
  TDList_destroy(&num1);
  TDList_destroy(&num2);
  TDList_destroy(&sum);
  return 0;
}