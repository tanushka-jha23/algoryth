#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

typedef struct pripq{
    Dynamic_array* array;
}Priq;

Priq* createPq(){
    Priq* q = (Priq*)malloc(sizeof(Priq));
    Dynamic_array* d = createDynamicArray();
    q->array = d;
    
    return q;
}

int enqueue(Priq* q, int v){
    push(q->array, v);
    int k = q->array->fill;
    while(k > 0){
        if(*(q->array->pointer + (k - 1)/ 2) < v){
            *(q->array->pointer) = *(q->array->pointer + (k - 1)/ 2);
            *(q->array->pointer + (k - 1)/ 2) = v;
        }
        k = (k - 1) / 2;
    }
    return 0;
}

int main(){
    Priq* p = createPq();
    enqueue(p, -1);
    enqueue(p, 9);
    enqueue(p, 5);
    enqueue(p, 0);
    enqueue(p, -100);
    printArray(p->array);
    printf("\n");

    return 0;
}