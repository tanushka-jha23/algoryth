#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct linkedlist{
    int size;
    Node* head;
    Node* tail;
}LinkedList;

LinkedList* createLinkedList(){
    LinkedList* a = (LinkedList*)malloc(sizeof(LinkedList));
    (*a).size = 0;
    return a;
}

int push(LinkedList* a, int v){
    Node* p = (Node*)malloc(sizeof(Node));
    (*p).value = v;
    
    if((*a).size == 0){
        (*a).head = p;
    }
    else if((*a).size == 1){
        (*a).tail = p;
        (*(*a).head).next = (*a).tail;
    }
    else{
        (*(*a).tail).next = p;
        (*a).tail = (*(*a).tail).next;
    }

    (*a).size = (*a).size + 1;

    return 0;
}

int pop(LinkedList* a, int i){
    int j;
    Node* n = (*a).head;
    for(j = 0; j < i - 1 ; j++){
        n = (*n).next;
    }
    int t = (*(*n).next).value;
    (*n).next = (*(*n).next).next;

    return t;
}

int get(LinkedList* a, int i){
    int j;
    Node* n = (*a).head;
    for(j = 0; j < i; j++){
        n = (*n).next;
    }
    
    return (*n).value;
}

int printList(LinkedList* a){
    printf("[");
    int j = 1;
    Node* n = (*a).head;
    while(j < (*a).size){
        if(j == (*a).size - 1){
            printf("%d", (*n).value);
        }
        else{
            printf("%d, ", (*n).value);
        }
        n = (*n).next;

        j = j + 1;
    }
    printf("]");
    printf("\n");

    return 0;
}

int main(){
    LinkedList* a = createLinkedList();
    push(a, 3);
    push(a, -5);
    push(a, 10);
    push(a, 16);
    push(a, 55);

    int p = pop(a, 2);
    int d = get(a, 2);
    printf("%d, %d \n", p, d);
    printList(a);
}

