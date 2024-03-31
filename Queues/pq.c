#include "../Array and Linked list/dynar.c"

//In a priority queue, every i-th element is greater in value than every (2i+1)-th and (2i+2)th element.
//Whenever a new element is enqueued/dequeued, priority queue shall arrange itself so that the abovementioned rule is not broken.
//The process to arrange elements in this way is called Heapifying.

typedef struct priority_queue {
    DynamicArray* A;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->A = createDynamicArray();
    return q;
}

int swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int nq(PriorityQueue* q, float x) {
    push(q->A, x);
    int i = q->A->fill;
    while(x >= *(q->A->pointer+(i-1)/2) && i > 0) {
        *(q->A->pointer+i) = *(q->A->array+(i-1)/2);
        *(q->A->pointer+(i-1)/2) = x;
        i = (i-1)/2;
    }
    return 0;
}

int main(){
    Priq* p = createPriorityQueue();
    nq(p, -1);
    nq(p, 9);
    nq(p, 5);
    nq(p, 0);
    nq(p, -100);
    printArray(p->array);
    printf("\n");

    return 0;
}