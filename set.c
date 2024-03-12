#include <stdio.h>
#include <stdlib.h>
#include "dynar.c"

typedef struct set{
    Dynamic_array* array;
}Set;

Set* createSet(){
    Set* s = (Set*)malloc(sizeof(Set));

    return s;
}

int checkMember(Set* a, int v){
    int i;
    for(i = 0; i < (*(*a).array).length; i++){
        if(*((*(*a).array).pointer + i) == v){
            return 1;
        }
    }
    return -1;
}

int add(Set* a, int v){
    int i;
    int number = -1;
    for(i = 0; i < (*(*a).array).length; i++){
        if(*((*(*a).array).pointer + i) == v){
            number = 0;
        }
    }
    if(number == -1){
        push((*a).array, v);
    }

    return 0;
}

int discard(Set* a, int v){
    int i;
    for(i = 0; i < (*(*a).array).length; i++){
        if(*((*(*a).array).pointer + i) == v){
            pop((*a).array, i);
        }
    }   
    return 0;
}

int printSet(Set* a){
    printf("{");
    int i;
    for(i = 0; i < (*(*a).array).length; i++){
        printf("%d ,", *((*(*a).array).pointer + i));
    }
    printf("}");
}

int main(){
    Set* p = createSet();
    add(p, 2);
}