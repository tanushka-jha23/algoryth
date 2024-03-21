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

int swap(int a, int b){
    int t = a;
    a = b;
    b = t;

    return 0;
}


int enqueue(Priq* q, int v){
    push(q->array, v);
    
    if(q->array->fill != 0){
        int k = q->array->fill + 1;
        while(k > 0){
            if(*(q->array->pointer + (k - 1)/ 2) < v){
                swap(*(q->array->pointer + (k-1)/2), v);
            }

            k = (k - 1) / 2;
        }
    }
    return 0;
}

int main(){
    Priq* p = createPq();
    enqueue(p, 5);
    enqueue(p, 9);
    enqueue(p, -1);
    enqueue(p, 0);
    printArray(p->array);
    printf("\n");

    return 0;
}