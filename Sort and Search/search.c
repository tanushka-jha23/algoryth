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

//binary search O[log n]
int binary_search(int*p, int a, int b, int v){
    if(b - a == 1){
        if(get(p, a) == v){
            return a;
        }
        return -1;
    }
    int c = (a + b) / 2;
    if(get(p, c) == v){
        return c;
    }
    else if(get(p, c) > v){
        binary_search(p, a, c, v);
    }
    else{
        binary_search(p, c, b, v);
    }
}


