#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* dynamic_array(){
    int* p = (int*)malloc(7);
    *p = 5;
    *(p + 1) = -1;
    int i = 0;
    while(i < *p){
        *(p + i + 2) = 0;

        i = i + 1;
    }
    return p;
}

int push(int* p, int v){
    *(p + 1) = 1;
    if(*(p + 1) > 5){
        int* q = (int*)malloc((*p) * 2 + 2);
        *q = (*p) * 2;

        q
    }
        int i = 0;
        while(i < *p){
            
        }
    }
}