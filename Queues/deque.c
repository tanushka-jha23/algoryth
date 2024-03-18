#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}Node;

typedef struct deque{
    int fill;
    Node* front;
    Node* back;
}Deque;

Deque* createDeque(){
    Deque* d = (Deque*)malloc(sizeof(Deque));
    d->fill = -1;
    return d;
}

int pushBack(Deque* d, int v){
    d->fill = d->fill + 1;
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = v;
    if(d->fill == 0){
        d->front = d->back = n;
    }
    else if(d->fill == 1){
        d->back = n;
        d->front->next = d->back;
        d->back->prev = d->front;
    }
    else{
        d->back->next = n;
        n->prev = d->back;
        d->back = d->back->next;
    }
    
    return 0;  

}

int pushFront(Deque* d, int v){
   d->fill = d->fill + 1;
   Node* n = (Node*)malloc(sizeof(Node));
   n->value = v;
   if(d->fill == 0){
        d->front = d->back = n;
    }
   else if(d->fill == 1){
        n->next = d->front;
        d->front->prev = n;
        d->front = d->front->prev;
    }  
    else{
        d->front->prev = n;
        n->next = d->front;
        d->front = d->front->prev;
    }
   return 0;
}

int popFront(Deque* d){
    d->fill = d->fill - 1;
    int p = d->front->value;
    d->front = d->front->next;

    return p;
}

int popBack(Deque* d){
    d->fill = d->fill - 1;
    int p = d->back->value;
    d->back = d->back->prev;

    return p;
}


int prettyPrint(Deque* d){
    printf("[");
    int i;
    Node* n = d->front;
    for(i = 0; i < d->fill; i++){
        printf("%d ,", n->value);

        n = n->next;
    }
    printf("%d", n->value);
    printf("]");
    printf("\n");
    return 0;
}


