#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

int abs(int n){
  if(n < 0){return (-1 * n);}
  return n;
}

void _nqueen(Dynamic_array* array, Dynamic_array* aux, Dynamic_array* chosen, int n, int* count_ptr){
  if(n > array->fill){
    printArray(aux);
    printf("\n");
    Dynamic_array* a_i = createDynamicArray();
    Dynamic_array* a_j = createDynamicArray();
    for(int i=0; i < aux->fill+1; i++){
      if(aux->pointer[i]){
        push(a_i, aux->pointer[i]/n);
        push(a_j, aux->pointer[i] -(aux->pointer[i]/n * n));
      }
    }
    for(int i=0; i < a_i->fill+1; i++){
      for(int j=1; j < a_i->fill+1; j++){
        *count_ptr += !(a_i->pointer[i] == a_j->pointer[j] ||
          a_j->pointer[i] == a_j->pointer[j] ||
          abs(a_i->pointer[i] - a_j->pointer[i]) == abs(a_i->pointer[j] - a_j->pointer[j]));
      }
    }
    printf("%d\n", *count_ptr); 
    freeDynamicArray(a_i);
    freeDynamicArray(a_j);
    return;
  } 
  for(int i = 0; i < array->fill+1; i++){
    if(chosen->pointer[i]){continue;}
    i[chosen->pointer] = 1;
    push(aux, array->pointer[i]);
    _nqueen(array, aux, chosen, n+1, count_ptr);
    chosen->pointer[i] = 0;
    pop(aux, aux->fill);
  }
}

int nqueen(int n){
  Dynamic_array* d = createDynamicArray();
  int i;
  for(i = 0; i < n; i++){
    push(d, 1);
  }
  for(; i < n*n; i++){
    push(d, 0);
  }

  Dynamic_array* chosen = createDynamicArray();
  for(int i = 0; i < n*n; i++){
    push(chosen, 0);
  }

  int count;
  Dynamic_array* aux = createDynamicArray();

  _nqueen(d, aux, chosen, 0, &count);
  freeDynamicArray(d);
  freeDynamicArray(aux);
  freeDynamicArray(chosen);
  return count;
}

int main() {
  nqueen(3);

  return 0;
}

