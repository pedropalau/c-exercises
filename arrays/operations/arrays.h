#ifndef C_ARRAY_H

#define C_ARRAY_H

#include <stdbool.h>

#include "../array-constants.h"

typedef struct array
{
	// The `size` of the array, this mean
	// that we create the array with an specific size
	// on memory. If the size is reached then we need to resize
	// the array like a dynamic one
	size_t size;

	// The `length` of the array.
	// Represent the total items the array have.
	int count;

	// The items of the array
	/*@partial@*/ /*@in@*/ /*@null@*/ int *items;
} array;

/**
 * Create a new array object with an specific size
 */
extern /*@out@*/ /*@notnull@*/ array *array_create(int size);

/**
 * Push one element onto the end of array
 */
extern void array_push(array *arr, int item);

/**
 * Set the element on the specific inex
 */
extern void array_set(/*@partial@*/ array *arr, int item,
                      int index) /*@modifies *arr->items@*/;

/**
 * Resize the array
 */
static /*@unused@*/ void array_resize(/*@in@*/ array *arr);

/**
 * Pop the element of the end of array
 */
extern int array_pop(array *arr);

/**
 * Shift an element off the beginning of array
 */
extern int array_shift(array *arr);

/**
 * Insert a new item in the array before position `index`.
 */
extern void array_insert(/*@in@*/ array *arr, int item,
                         int index) /*@modifies arr@*/;

/**
 * Searches the array for a given value and returns
 * the first corresponding key if successful
 */
extern int array_search(array *arr, int item);

/**
 * Calculate the product of values in an array
 */
extern int array_product(array *arr);

/**
 * Return the number of occurrences of `x` in the array.
 */
extern int array_count(array *arr, int x);

/**
 * Delete the array
 */
extern void
array_free(/*@only@*/ /*@null@*/ /*@partial@*/ array *arr) /*@modifies arr@*/;

/**
 * Checks if a value exists in an array
 */
extern bool in_array(array *arr, int *item);

#endif
