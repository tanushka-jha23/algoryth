#include<stdio.h>
#include<stdlib.h>
#include "../Array and Linked list/linked_list.c"

typedef struct queue{
    LinkedList* list;
}Queue2;

Queue2* consQueue(){
    LinkedList* l = createLinkedList();
    Queue2* q = (Queue2*)malloc(sizeof(Queue2));
    q->list = l;

    return q;
}

int enqueue(Queue2* d, int v){
    push(d->list, v);

    return 0;
}

int dequeue(Queue2* d){
    pop(d->list, 0);

    return 0;
}

int main(){
    Queue2* q = consQueue();
    enqueue(q, 5);
    enqueue(q, -10);
    enqueue(q, 15);
    printList(q->list);

    return 0;
}