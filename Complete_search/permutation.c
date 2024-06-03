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

int main(){
  Dynamic_array* array = createDynamicArray();
  push(array, 6);
  push(array, 2);
  push(array, 9);
  Dynamic_array* aux = createDynamicArray();
  Dynamic_array* chosen = createDynamicArray();
  push(chosen, 0);
  push(chosen, 0);
  push(chosen, 0);
  permutation(array, aux, 0, chosen);


  return 0 ;
}


