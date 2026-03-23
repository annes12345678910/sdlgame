#include <stdlib.h>
#pragma once

typedef struct
{
    void* data;
    unsigned int len;
} Array;

void free_array(Array* ar) {
    free(ar->data);
    ar->data = NULL;
}

Array create_heap_array(int sizeoftype, unsigned int len) {
    Array ar;
    ar.data = malloc(sizeoftype * len);
    ar.len = len;
    return ar;
}

void resize_array(Array* ar, int amount) {
    ar->data = realloc(ar->data, ar->len + amount);
}