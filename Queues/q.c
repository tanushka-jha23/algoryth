#include <stdio.h>
#include <stdlib.h>
#include "../Array and Linked list/dynar.c"

typedef struct queue{
    Dynamic_array* Dynamic_array;
}Queue;

//constructor

Queue* constructQueue(){
    Dynamic_array* d = createDynamicArray();
    Queue* a = (Queue*)malloc(sizeof(Queue));
    (*a).Dynamic_array = d;
    return a;
}

//enqueue(just like push in case of dynamic array)

int enqueue(Queue* a, int v){
    push((*a).Dynamic_array, v);

    return 0;
}

//dequeue(remove the first value of queue)

int dequeue(Queue* a){
    pop((*a).Dynamic_array, 0);

    return 0;
}
