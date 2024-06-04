#include <stdio.h>
#include "../Array and Linked list/dynar.c"
void permutation(Dynamic_array* array, Dynamic_array* aux, int n, Dynamic_array* chosen){
  if(n >= array->fill+1){
    printArray(aux);
    return;
  }
  for(int i = 0; i < array->fill+1; i++){
    if(*(chosen->pointer + i)){
      continue;
    }
    *(chosen->pointer + i) = 1;
    push(aux, *(array->pointer + i));
    permutation(array, aux, (n+1), chosen);
    *(chosen->pointer + i) = 0;
    pop(aux, aux->fill);
  }

  return;
}

