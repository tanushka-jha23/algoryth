#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

typedef struct priq{
    Dynamic_array* array;
}Priq;

Priq* createPq(){
    Priq* q = (Priq*)malloc(sizeof(Priq));
    Dynamic_array* d = createDynamicArray();
    q->array = d;
    
    return q;
}
int swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;

    return 0;
}

int enqueue(Priq* q, int v){
    push(q->array, v);
    int k = q->array->fill;
    while(k > 0){
        if(*(q->array->pointer + ((k - 1)/ 2)) <= v){
            int t = *(q->array->pointer + k);
            *(q->array->pointer + k) = *(q->array->pointer + (k - 1)/2);
            *(q->array->pointer + (k - 1)/2) = t;
        }
        k = (k - 1) / 2;
    }
    return 0;
}

int dequeue(Priq* q){
    swap(q->array->pointer, q->array->pointer + q->array->fill);
    int t = pop(q->array, q->array->fill);
    int k = 0;
    while((2*k + 1) <= q->array->fill){
        int max;
        if(*(q->array->pointer+2*k+2) > q->array->fill){
            max = 2*k+1;
        }
        else{
            if(*(q->array->pointer + 2*k+1) > *(q->array->pointer + 2*k+2)){
                max = 2*k + 1;
            }
            else{
                max = 2*k + 2;
            }
        }
        if(*(q->array->pointer + max) > *(q->array->pointer + k)){
            swap(q->array->pointer + k, q->array->pointer + max);
        }
        k = max;
    }
    return t;
}

int main(){
    Priq* p = createPq();
    enqueue(p, -100);
    enqueue(p, 9);
    enqueue(p, 5);
    enqueue(p, 0);
    enqueue(p, 10);
    enqueue(p, 15);
    enqueue(p, -23);
    printArray(p->array);
    printf("%d", a);
    printf("\n");

    return 0;
}