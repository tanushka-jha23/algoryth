#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string{
    int length;
    char* character;
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
    s->character = t;

    return s;
}

int equalStrings(String* a, String* b){
    if(a->length != b->length){
        return 0;
    }
    else{
        int i;
        for(i = 0; i < a->length; i++){
            if(*(a->character + i) != *(b->character + i)){
                return 0;
            }
        }
        return 1;
    }
}
