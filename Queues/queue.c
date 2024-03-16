#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

typedef struct queue{
    Dynamic_array* Dynamic_array;
}Queue;

Queue* constructQueue(Dynamic_array* d){
    Queue* a = (Queue*)malloc(sizeof(Queue));
    (*a).Dynamic_array = d;
    return a;
}

int enqueue(Queue* a, int v){
    push((*a).Dynamic_array, v);

    return 0;
}

int dequeue(Queue* a){
    pop((*a).Dynamic_array, 0);

    return 0;
}

int main(){
    Dynamic_array* d = createDynamicArray();
    push(d, 1);
    push(d, -5);
    push(d, 12);
    push(d, -3);
    push(d, 10);
    Queue* q = constructQueue(d);
    printArray(q->Dynamic_array);
    enqueue(q, 5);
    printArray(q->Dynamic_array);
    dequeue(q);
    printArray(q->Dynamic_array);

    return 0;
}