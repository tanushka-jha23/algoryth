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
    while(k != NULL && !equalStrings(k->key, s)){
        k = k->next;
    }
    return k;
}

int insert(Hashmap* h, String* s, int v){
    kvPair* t = *(h->array + fnv1a_hash(s));
    if(entry(h, s) == NULL && t == NULL){
        kvPair* k = (kvPair*)malloc(sizeof(kvPair));
        k->key = s;
        k->value = v;
        k->next = NULL;
        *(h->array + fnv1a_hash(s)) = k;
    }
    else if(entry(h, s) == NULL && t != NULL){
        kvPair* k = (kvPair*)malloc(sizeof(kvPair));
        k->key = s;
        k->value = v;
        while(t->next != NULL){
            t = t->next;
        }
        k->next = NULL;
        t->next = k;
    }
    else{
        kvPair* kv = entry(h, s);
        kv->value = v;
    }
    return 0;
}

int discard(Hashmap* h, String* s){
    kvPair* kv = entry(h, s);
    if(kv == NULL){
        return -1;
    }
    else if(kv->next == NULL){
        int v = kv->value;
        free(kv);
        return v;
    }
    else{
        kvPair* kvp = *(h->array + fnv1a_hash(s));
        if(entry(h, s) == kvp){
            kvPair* t = entry(h, s);
            int v = t->value;
            kvp = kvp->next;
            free(t);
            return v;
        }
        else{
            while(kvp->next != NULL){
                if(equalStrings(kvp->next->key, s)){
                    break;
                }
                kvp = kvp->next;
            }
            kvPair* t = kvp->next;
            int v = t->value;
            kvp->next = kvp->next->next;
            free(t);
            return v;
        }
    }
}



