#include <game/array.h>
#include <stdio.h>

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

void resize_array(Array* ar, int amount, int sizeoftype) {
    ar->data = realloc(ar->data, (ar->len + amount) * sizeoftype);
    ar->len += amount;
    if (!ar->data)
    {
        fprintf(stderr, "ARRAY ERROR, %p\n", ar->data);
        exit(300);
    }
    
}
