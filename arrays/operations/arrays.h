#ifndef C_ARRAY_H

#define C_ARRAY_H

#include <stdbool.h>

typedef struct array
{
    // The `size` of the array, this mean
    // that we create the array with an specific size
    // on memory. If the size is reached then we need to resize
    // the array like a dynamic one
    int size;

    // The `length` of the array. 
    // Represent the total items the array have.
    int count;

    // The items of the array
    int *items;
} array;

#endif
