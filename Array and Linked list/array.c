#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//array constructor
int* Array(int n) {
    int* p = (int*)malloc((n + 1) * sizeof(int)); 
    int i;
    *p = n;
    for(i = 1; i <= n; i++){
        *(p + i) = 0;
    }
    return p;
}
//function to read an element of the array
int get(int* a, int i) {
    return *(a + i + 1);
}
//modifying function of an array
int set(int* a, int i, int v){
    *(a + i + 1) = v;
    return 0;
}
//delete array from memory
int delete(int* a){
    free(a);
}
//method to print array
int printArray(int* a) {
    int i;
    printf("[ ");
    for(i = 0; i < *a; i++) {
        if(i == *a - 1){
            printf("%d ", get(a, i));
        }
        else{
            printf("%d, ", get(a, i));
        }
    }
    printf("]\n");
    return 0;
}