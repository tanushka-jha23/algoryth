#include <stdio.h>
#include <stdlib.h>

int** dynamic_array(){
    int** t = (int**)malloc(sizeof(int*));
    int* p = (int*)malloc(7 * sizeof(int));
    *p = 5;
    *(p + 1) = -1;
    int i = 0;
    while(i < *p){
        *(p + i + 2) = 0;

        i = i + 1;
    }
    *t = p;
    return t;
}

int get(int** p, int i){
    return *(*(p) + i + 2);
}

int push(int** p, int v){
    *(*(p) + 1) = *(*(p) + 1) + 1;
    int* q;
    if(*(*(p) + 1) >= **p){
        int* q = (int*)malloc((*(*p) * 2 + 2) * sizeof(int));
        *q = *(*p) * 2;
        *(q + 1) = *(*(p) + 1);

        int i = 0;
        while(i < *(q + 1)){
            *(q + i + 2) = get(p, i);

            i = i + 1;
        }
        *(q + i + 2) = v;

        *p = q;
    }
    else{
        *(*(p) + *(*(p) + 1) + 2) = v;

    }
    return 0;
}

int pop(int** p, int i){
    *(*(p) + 1) = *(*(p) + 1) - 1;
    int a = (*(*(p) + i + 2));

    if((*(*(p) + 1) < (**p)/2)  &&  **p > 5){
        int* q = (int*)malloc(((**p)/2) * sizeof(int));
        *q = (**p)/2;
        *(q + 1) = *(*(p) + 1);

        int j = 0;
        while(j < i){
            *(q + j + 2) = get(p, j);

            j = j + 1;
        }
        while(j <= *(q + 1)){
            *(q + j + 2) = get(p, j + 1);

            j = j + 1;
        }
        *p = q;
    }
    else{
        int j;
        for(j = i; j < *(*p + 1) + 1; j++){
            *((*p) + j + 2) = get(p, j + 1);
        }
    }
    return a;
}

int printArray(int** a) {
    int i;
    printf("[ ");
    for(i = 0; i < *(*(a) + 1) + 1 ; i++) {
        if(i == *(*(a) + 1)){
            printf("%d", get(a, i));
        }
        else{
            printf("%d, ", get(a, i));
        }
    }
    printf("]\n");
    return 0;
}

int main(){
    int**a = dynamic_array();
    push(a, 12);
    push(a, 10);
    push(a, 40);
    push(a, 53);
    push(a, -10);
    push(a, 0);
    push(a, 17);


    printArray(a);
    pop(a, 1);
    printArray(a);
    pop(a, 3);
    printArray(a);
}
