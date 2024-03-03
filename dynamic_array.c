#include <stdio.h>
#include <stdlib.h>

int* dynamic_array(){
    int* p = (int*)malloc(7 * sizeof(int));
    *p = 5;
    *(p + 1) = -1;
    int i = 0;
    while(i < *p){
        *(p + i + 2) = 0;

        i = i + 1;
    }
    return p;
}

int get(int* p, int i){
    return *(p + i + 2);
}

int* push(int* p, int v){
    *(p + 1) = *(p + 1) + 1;
    int* q;
    if(*(p + 1) >= *p){
        int* q = (int*)malloc(((*p) * 2 + 2) * sizeof(int));
        *q = (*p) * 2;
        *(q + 1) = *(p + 1);

        int i = 0;
        while(i < (*(q + 1))){
            *(q + i + 2) = get(p, i);

            i = i + 1;
        }
        *(q + i + 2) = v;

        return q;
    }
    else{
        *(p + *(p + 1) + 2) = v;

        return p;
    }
}

int printArray(int* a) {
    int i;
    printf("[ ");
    for(i = 0; i < *(a); i++) {
        if(i == *a - 1){
            printf("%d", get(a, i));
        }
        else{
            printf("%d, ", get(a, i));
        }
    }
    printf("]\n");
    return 0;
}