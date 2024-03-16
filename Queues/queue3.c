#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int* front;
    int* pointer;
    int* back;
    int size;
}Queue;

Queue* consQ(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    
    q->size = -1;

    return 0;
}

int enqueue(Queue* q, int v){
    (*q).size = (*q).size + 1;
    
    int* p = (int*)malloc(((*q).size + 1) * sizeof(int));

    if((*q).size == 0){
        *p = v;
        (*q).front = p;
    }
    else{
        (*q).front = p;
        int i;
        for(i = 0; i < (*q).size; i++){
            *(p + i) = *((*q).pointer + i);
        }
        *(p + i) = v;
        (*q).back = p + i;
    }

    (*q).pointer = p;

    return 0;
}

int PrintQueue(Queue* q){
    int i;
    for(i = 0; i < (*q).size + 1; i++){
        printf("%d", *((*q).pointer + i));
    }
    printf("\n");

    return 0;
}

int main(){
    Queue* q = consQ();
    enqueue(q, 5);
    PrintQueue(q);;

    return 0;
}