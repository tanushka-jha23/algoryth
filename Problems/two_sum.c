#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

void two_sum(Dynamic_array* aux, Dynamic_array* array, int n, int k, int* count_ptr){
  if( n < 0 ){
    if(aux->fill == 1 && (*(array->pointer + *(aux->pointer)) + *(array->pointer + *(aux->pointer + 1)) == k)){
      *count_ptr = *count_ptr + 1;
    }

    return;
  }
  push(aux, n);
  two_sum(aux, array, n-1, k, count_ptr);
  pop(aux, aux->fill);
  two_sum(aux, array, n-1, k, count_ptr);

  return;
}

