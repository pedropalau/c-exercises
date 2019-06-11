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
	/*@only@*/ /*@null@*/ int *items;
} array;

/**
 * Create a new array object with an specific size
 */
extern /*@only@*/ /*@notnull@*/ array *array_create(int size);

/**
 * Push one element onto the end of array
 */
extern void array_push(array *arr, int item);

/**
 * Set the element on the specific inex
 */
extern void array_set(array *arr, int item, int index);

/**
 * Resize the array
 */
/*@unused@*/ static void array_resize(array *arr);

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
extern void array_insert(array *arr, int item, int index);

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
 * Count all elements in an array
 */
extern int array_count(array *arr);

/**
 * Delete the array
 */
/*@null@*/ extern void
  array_free(/*@only@*/ /*@null@*/ array *arr) /*@modifies arr@*/;

/**
 * Checks if a value exists in an array
 */
extern bool in_array(array *arr, int *item);

#endif
