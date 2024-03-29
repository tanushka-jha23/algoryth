#include <stdio.h>
#include <stdlib.h>
#include "dynar.c"

typedef struct iterator{
    int size;
    int currIndex;
    int* p;
}Iterator;

Iterator* constructIterator(Dynamic_array* d){
    Iterator* t = (Iterator*)malloc(sizeof(Iterator));
    int* a = (int*)malloc((*d).fill*sizeof(int));
    int i;
    for(i = 0; i < (*d).fill + 1; i++){
        *(a + i) = *((*d).pointer + i);
    }
    (*t).size = (*d).fill;
    (*t).currIndex = 0;
    (*t).p = a;

    return t;
}

int consume(Iterator* a){
    int v = *((*a).p + (*a).currIndex);
    if((*a).currIndex == (*a).size){
        free((*a).p);
        free(a);
    }
    else{
        (*a).currIndex = (*a).currIndex + 1;
    }
    return v;
}