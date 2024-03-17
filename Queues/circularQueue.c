#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int front;
    int back;
    int fill;
    int* pointer;
    int size;
}Queue;

//constructor of queue
Queue* consqueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    int* p = (int*)malloc(sizeof(int));
    q->front = -1;
    q->back = - 1;
    q->fill = -1;
    q->size = 5;
    q->pointer = p;

    return q;
}

int resize(Queue* q, int s){
    int* t = (int*)malloc(s * sizeof(int));
    int i; 
    for(i = q->front + 1; i <= (q->front + q-> size); i++){
        *(t + i - q->front - 1) = *(q->pointer + i%q->size);
    }
    free(q->pointer); 
    q->pointer = t;
    q->back = q->size - 1;
    q->front = -1;
    q->size = q->size * 2;
}

int enqueue(Queue* q, int v){
    q->fill += 1;
    if(q->fill >= q->size){
        resize(q, q->size * 2);
    }
    q->back = (q-> back + 1)%q->size;
    *(q->pointer + q->back) = v;

    return 0;
}

int dequeue(Queue* q){
    q->fill = q->fill - 1;
    if(q->fill < q->size/2 && q->size/2 > 5){
        resize(q, q->size/2);
    }
    q->front = (q->front + 1) % q->size;
    return *(q->pointer + q->front) ;
}

int printQueue(Queue* q){
    int i;
    printf("|");
    for(i = 1; i <= q->fill; i++){
        printf("%d ,", *(q->pointer + (q->front + i)%q->size));
    }
    printf("%d", *(q->pointer + (q->front + i)%q->size));

    printf("|");
    printf("\n");

    return 0;
}

int main(){
    Queue* q = consqueue();
    push(q, 2);
    push(q, 5);
    push(q, -10);
    printQueue(q);
    int a = pop(q);
    printQueue(q);
    printf("%d\n", a);

    return 0;
}