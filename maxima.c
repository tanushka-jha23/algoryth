#include <stdio.h>
#include "array.c"

//application of binary maxima
int binary_maxima(int* p, int a, int b){
    int c = (a + b) / 2;
    if(get(p, c) > get(p, c + 1) && get(p, c) > get(p, c - 1)){
        return get(p, c);
    }
    else{
        if(get(p, c + 1) > get(p, c)){
            binary_maxima(p, c, b);
        }
        else{
            binary_maxima(p, a, c);
        }
    }
}

