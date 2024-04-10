#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string{
    int length;
    char* str;
}String;

String* createString(char* c){
    String* s = (String*) malloc(sizeof(String));
    int i = 0;
    while(*(c + i) != '\0'){
        i = i + 1;
    }
    s->length = i;
    char* t = (char*)malloc(s->length * sizeof(char));
    for(i = 0; i < s->length; i++){
        *(t + i) = *(c + i);
    }
    s->str = t;

    return s;
}

