#include <stdio.h>
#include <stdlib.h>
#include "dynar.c"

typedef struct set{
    Dynamic_array* array;
}Set;
//constructor
Set* createSet(){
    Set* s = (Set*)malloc(sizeof(Set));
    (*s).array = createDynamicArray();
    return s;
}

int checkMember(Set* a, int v){
    int i;
    for(i = 0; i <= (*(*a).array).fill; i++){
        if(*((*(*a).array).pointer + i) == v){
            return 1;
        }
    }
    return -1;
}

int add(Set* a, int v){
    int number = checkMember(a, v);
    if(number == -1){
        push((*a).array, v);
    }

    return 0;
}

int discard(Set* a, int v){
    int i;
    for(i = 0; i < (*(*a).array).fill; i++){
        if(*((*(*a).array).pointer + i) == v){
            pop((*a).array, i);
        }
    }   
    return 0;
}

int printSet(Set* a){
    printf("{");
    int i;
    for(i = 0; i <= (*(*a).array).fill; i++){
        if(i == (*(*a).array).fill){
            printf("%d", *((*(*a).array).pointer + i));
        }
        else{
            printf("%d ,", *((*(*a).array).pointer + i));
        }
    }
    printf("}");
}

int main(){
    Set* p = createSet();
    add(p, 2);
    add(p, 5);
    add(p, 0);
    int a = checkMember(p, 0);
    printSet(p);
    discard(p, 5);
    printSet(p);
    printf("%d\n", a);

    return 0;
}