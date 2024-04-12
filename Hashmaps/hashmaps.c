#include <stdio.h>
#include <stdlib.h>
#include "../Strings/string.c"

typedef struct keyvaluepair{
    String* key;
    int value;
    struct keyvaluepair* next;
}kvPair;

typedef struct hashmap{
    kvPair** array;
}Hashmap;

int fnv1a_hash(String* s){
    long int fnv_prime = 16777619;
    unsigned long int hash = 2166136261;
    int i;
    for(i = 0; i < s->length; i++){
        hash = hash ^ *(s->character + i);
        hash = hash * fnv_prime;
    }

    return hash % 10;
}
//address of collection of addresses of key-value-pairs
Hashmap* createhashmap(){
    Hashmap* h = (Hashmap*)malloc(sizeof(Hashmap));
    kvPair** k = (kvPair**)malloc(sizeof(kvPair*) *  10);
    h->array = k;
    for(int i = 0; i < 10; i++){
        *(h->array + i) = NULL;
    }
    return h;
}

kvPair* entry(Hashmap* h, String* s){
    kvPair* k = *(h->array + fnv1a_hash(s));
    while(k != NULL){
        if(equalStrings(k->key, s)){
            kvPair* p = k;
        }
        else{
            k = k->next;
        }
    }
    return p;
}

int insert(Hashmap* h, String* s, int v){
    if(entry(h, s) == NULL){
        kvPair* k = (kvPair*)malloc(sizeof(kvPair));
        k->key = s;
        k->value = v;
        *(h->array + fnv1a_hash(s)) = k;
    }
    else{
        kvPair* kv = entry(h, s);
        kv->key = v;
    }
    return 0;
}

int discard(Hashmap* h, String* s){
    kvPair* kv = *(h->array + fnv1a_hash(s));

    while(kv != NULL && !equalStrings(kv->key, s)){
        kv = kv->next;
    }
    kv->value 
}


