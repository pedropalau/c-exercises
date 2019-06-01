#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

#define ARRAY_SIZE      10

/**
 * Create a new array object with an specific size
 */
array *array_create(int size);

/**
 * Push one element onto the end of array
 */
void array_push(array *arr, int item);

/**
 * Set the element on the specific inex
 */
void array_set(array *arr, int item, int index);

/**
 * Resize the array
 */
void array_resize(array *arr);

/**
 * Pop the element of the end of array
 */
int array_pop(array *arr);

/**
 * Shift an element off the beginning of array
 */
int array_shift(array *arr);

/**
 * Insert a new item in the array before position `i`. 
 */
void array_insert(array *arr, int *item, int i);

/**
 * Searches the array for a given value and returns 
 * the first corresponding key if successful
 */
int array_search(array *arr, int *item);

/**
 * Calculate the product of values in an array
 */
int array_product(array *arr);

/**
 * Count all elements in an array
 */
int array_count(array *arr);

/**
 * Delete the object
 */
void array_free(array *arr);

/**
 * Reset the object
 */
void array_reset(array *arr);

/**
 * Checks if a value exists in an array
 */
bool in_array(array *arr, int *item);

/**
 * Push one element onto the end of array
 */
void array_push(array *arr, int item)
{
    if (arr->size <= arr->count)
    {
        array_resize(arr);
    }

    array_set(arr, item, arr->count);
    arr->count += 1;
}

/**
 * Set the element on the specific inex
 */
void array_set(array *arr, int item, int index)
{
    arr->items[index] = item;
}

/**
 * Resize the array
 */
void array_resize(array *arr)
{
    int size_for_resize = (arr->size * ARRAY_SIZE) * sizeof(int);
    // Attempts to resize the memory block reserved for items
    arr->items = realloc(arr->items, size_for_resize);
    arr->size *= ARRAY_SIZE;
}

/**
 * Pop the element of the end of array
 */
int array_pop(array *arr)
{
    if (arr->count > 0)
    {
        int i = arr->count - 1;
        int last = arr->items[i];
        for (;i < arr->count - 1; i++)
        {
            arr->items[i] = arr->items[i + 1];
        }
        arr->count -= 1;
        return last;
    }

    return -1;
}
