#include <stdio.h>
#include <stdlib.h>

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
//bubble sort O[n^2]
int  bubble_sort(int* a) {
    int j;
    for(j = 0; j < *a; j++){
        int i = 1;
        int n = (*a) - j;
        for(i = 1 ; i < n; i++){
            if(*(a + i) > *(a + i + 1)){
                int p = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = p;
            }
        }
    }
    return 0;
}

//merge algorithm O[n]
int* merge(int *p, int a, int c, int b){
    int* t = Array(b - a);
    int i = a;
    int j = c;
    int k = 0;
    while(i < c && j <= b){
            if(get(p, i) <= get(p, j)){
                set(t, k, get(p, i));
                i = i + 1;
            }
    
            else{
                set(t, k, get(p, j));
                j = j + 1;
            }
        k = k + 1;
    }
    int r;
    if(i >= c){
        r = j;
    }
    else{
        r = i;
    }
    while(k < *t){
        set(t, k, get(p, r));
        r = r + 1;
        k = k + 1;
    }
    i = 0;
    for(i = a; i < b; i++){
        set(p, i, get(t, i));
    }
    delete(t);
}


