#include <stdlib.h>
#pragma once

typedef struct
{
    void* data;
    unsigned int len;
} Array;

void free_array(Array* ar);

Array create_heap_array(int sizeoftype, unsigned int len);

void resize_array(Array* ar, int amount, int sizeoftype);