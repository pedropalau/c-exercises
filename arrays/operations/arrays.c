#ifndef C_ARRAY

#define C_ARRAY

#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

/**
 * Create a new array object with an specific size
 */
/*@only@*/ /*@notnull@*/ array *array_create(int count)
{
	array *arr = NULL;
	do
	{
		arr = (array *) malloc(sizeof(array));
	} while (arr == NULL);

	arr->size = ARRAY_SIZE;
	arr->count = count;
	arr->items = NULL;

	do
	{
		arr->items = (int *) calloc(ARRAY_SIZE, sizeof(int));
	} while (arr->items == NULL);

	return arr;
}

/**
 * Push one element onto the end of array
 */
void array_push(array *arr, int item)
{
	if ((size_t) arr->count >= arr->size) { array_resize(arr); }

	array_set(arr, item, arr->count);
	arr->count += 1;
}

/**
 * Pop the element of the end of array
 */
int array_pop(array *arr)
{
	if (arr->count > 0 && arr->items != NULL)
	{
		int i = arr->count - 1;
		int last = arr->items[i];
		for (; i < arr->count - 1; i++) { arr->items[i] = arr->items[i + 1]; }
		arr->count -= 1;
		return last;
	}

	return -1;
}

/**
 * Shift an element off the beginning of array
 */
int array_shift(array *arr)
{
	if (arr->count > 0 && arr->items != NULL)
	{
		int i = 0;
		int first = arr->items[i];
		for (; i < arr->count; i++) { arr->items[i] = arr->items[i + 1]; }
		arr->count -= 1;
		return first;
	}

	return -1;
}

/**
 * Insert a new item in the array before position `index`.
 */
void array_insert(array *arr, int item, int index)
{
	if (arr->count > 0 && arr->items != NULL)
	{
		if (arr->size <= (size_t) arr->count) { array_resize(arr); }

		if (index >= arr->count) { array_push(arr, item); }
		else
		{
			int i = arr->count;
			for (; i >= index; i--) { array_set(arr, arr->items[i - 1], i); }
			array_set(arr, item, index - 1);
			arr->count += 1;
		}
	}
}

/**
 * Searches the array for a given value and returns
 * the first corresponding key if successful
 */
int array_search(array *arr, int item)
{
	int i = 0;

	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			if (arr->items[i] == item) { return i; }
		}
	}

	return -1;
}

/**
 * Calculate the product of values in an array
 */
extern int array_product(array *arr)
{
	int i = 0, product = 0;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			if (i == 0) { product = arr->items[i]; }
			else
			{
				product *= arr->items[i];
			}
		}
	}
	return product;
}

/**
 * Return the number of occurrences of `x` in the array.
 */
extern int array_count(array *arr, int x)
{
	int count = 0, i = 0;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			if (arr->items[i] == x) { count += 1; }
		}
	}
	return count;
}

/**
 * Set the element on the specific inex
 */
void array_set(array *arr, int item, int index)
{
	if (arr->items != NULL) { arr->items[index] = item; }
}

/**
 * Resize the array
 */
void array_resize(array *arr)
{
	size_t size_for_resize = (arr->size * ARRAY_SIZE) * sizeof(int);
	// Attempts to resize the memory block reserved for items
	arr->items = realloc(arr->items, size_for_resize);
	while (arr->items == NULL)
	{ arr->items = realloc(arr->items, size_for_resize); }
	arr->size *= ARRAY_SIZE;
}

/**
 * Delete the array and free the used memory
 */
/*@null@*/ void array_free(/*@only@*/ /*@null@*/ array *arr) /*@modifies arr@*/
{
	// array_reset(arr);
	if (arr != NULL)
	{
		free(arr->items);
		free(arr);
	}
}

#endif
