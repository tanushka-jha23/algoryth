#include <stdio.h>
#include <stdlib.h>
#include "array.c"

//linear search O[n]
int linear_search(int* p, int v){
    int i;
    for(i = 0; i < *p; i++){
        if(get(p, i) == v){
            return i;
        }
    }
}