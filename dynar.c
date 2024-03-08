#include <stdio.h>
#include <stdlib.h>

//dynamic array using struct

typedef struct dynamic_array{
    int length;
    int fill;
    int* pointer;
}Dynamic_array;

//constructor
Dynamic_array* createDynamicArray(){
    int* p = (int*)malloc(5 * sizeof(int));
    Dynamic_array* d = (Dynamic_array*)malloc(sizeof(Dynamic_array));
    (*d).length = 5;
    (*d).fill = -1;
    (*d).pointer = p;

    return d;
}
//push 
int push(Dynamic_array* d, int v){
    (*d).fill = (*d).fill + 1;
    if(((*d).fill >= (*d).length)){
        (*d).length = ((*d).length) * 2;
        int* a = malloc(((*d).length) * sizeof(int));

        int j;
        for(j = 0; j < (*d).fill; j++){
            *(a + j) =  *((*d).pointer + j);
        }
        *(a + j) = v;

        (*d).pointer = a;
    }

    *((*d).pointer + (*d).fill) = v;

    return 0;
}

//pop
int pop(Dynamic_array* d, int i){
    int a = *((*d).pointer + i);
    (*d).fill = (*d).fill - 1;

    if((*d).fill < ((*d).length / 2) && (*d).length > 5){
        (*d).length = (*d).length / 2;
        int* t = malloc((*d).length);

        int k = 0;
        while(k < i){
            *(t + k) = *((*d).pointer + k);
            
            k = k + 1;
        }
        while(k < (*d).fill + 1){
            *(t + k) = *((*d).pointer + k + 1);

            k = k + 1;
        }

        (*d).pointer = t;
    }
    else{
        int j;
        for(j = i; j < (*d).fill + 1; j++){
            *((*d).pointer + j) = *((*d).pointer + j + 1);
        }
    }
    return a;
}

int insert(Dynamic_array* d, int i, int v){
    (*d). fill = (*d).fill + 1;
    if((*d).fill >= (*d).length){
        (*d).length = (*d).length * 2;
        int* q = malloc(((*d).length) * sizeof(int));
        int j;
        for(j = 0; j < i; j ++){
            *(q + j) = *((*d).pointer + j);;
        }
        for(; j < (*d).fill ; j++){
            *(q + j + 1) = *((*d).pointer + j);
        }
        *(q + i) = v;
        (*d).pointer = q;
    }
    
   else{
        int j;
        for(j = (*d).fill - 1; j >= i; j--){
            *((*d).pointer + j + 1) = *((*d).pointer + j);
        }
        *((*d).pointer + i) = v;
    }

}

int printArray(Dynamic_array* d){
    printf("[ ");
    int j = 0;
    while(j < (*d).fill + 1){
        if(j == (*d).fill){
            printf("%d", *((*d).pointer + j));
        }
        else{
            printf("%d ,", *((*d).pointer + j));
        }
            
        j = j + 1;
    }
        
    printf("]");
    return 0;
}


int main(){
    
    Dynamic_array* a = createDynamicArray();
    push(a, 12);
    push(a, -15);
    push(a, 17);
    push(a, 23);
    push(a, 100);
    insert(a, 4, 15);

    printArray(a);
    printf("\n");

}