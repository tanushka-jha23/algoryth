#include <stdio.h>
#include <stdlib.h>

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

int getp(int* p, int i){
    return(*(p + i + 2));
}

int* push(int* p, int v){
    *(p + 1) = *(p + 1) + 1;
    if(*(p + 1) > *p){
        int* q = malloc((*p) * 2 + 2);
        *q = *p * 2;
        *(q + 1) = *(p + 1);

        int i = 0;
        while(i < *(q + 1) - 1){
            *(q + i + 2) = getp(p, i);

            i = i + 1;
        }
        *(q + i + 2) = v;

        free(p);
        int* p = q;
        return p;
    }
}
