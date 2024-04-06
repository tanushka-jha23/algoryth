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
        int p = *(q->array->pointer);
        if(2*k+1 < q->array->fill+1 && p < *(q->array->pointer + 2*k+1)){
            p = *(q->array->pointer + 2*k+1);
            k = 2*k + 1;
        }
        if(2*k+2 < q->array->fill+1 && p < *(q->array->pointer + 2*k+2)){
            p = *(q->array->pointer + 2*k+2);
            k = 2*k + 2;
        }
        else{
            break;
        } 
    } 
    return t;
}

int main(){
    Priq* p = createPq();
    enqueue(p, 2);
    enqueue(p, -7);
    enqueue(p, 100);
    printArray(p->array);
    printf("\n");
    dequeue(p);
    dequeue(p);
    printArray(p->array);
    printf("\n");

    return 0;
}

