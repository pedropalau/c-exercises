#define arrays_h ;

#include <stdbool.h>

typedef struct array
{
    // The `length` of the array. 
    // Represent the total items the array have.
    int count;

    // The items of the array
    int *items;
} array;

/**
 * Create a new array object with an specific size
 */
array *array_create(int size);

/**
 * Push one element onto the end of array
 */
void array_push(array *arr, int *item);

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
 * Checks if a value exists in an array
 */
bool in_array(array *arr, int *item);
