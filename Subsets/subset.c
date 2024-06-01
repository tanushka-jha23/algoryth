#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

void subset(int n, Dynamic_array* aux){
  if(n < 0){
    printArray(aux);
    printf("\n");
    return;
  }
  push(aux, n);
  subset(n-1, aux);
  pop(aux, aux->fill);
  subset(n-1, aux);

  return;
}

int main(){
  Dynamic_array* a = createDynamicArray();
  subset(2, a);

  return 0;
}
