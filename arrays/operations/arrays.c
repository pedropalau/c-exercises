#ifndef C_ARRAY

#define C_ARRAY

#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

/**
 * Create a new array object with an specific size
 */
array *array_create(int count)
{
	array *arr = (array *) malloc(sizeof(array));

	if (arr)
	{
		arr->size = ARRAY_SIZE;
		arr->count = count;
		arr->items = (int *) calloc(ARRAY_SIZE, sizeof(int));
	}

	return arr;
}

/**
 * Push one element onto the end of array
 */
void array_push(array *arr, int item)
{
	if (arr->count >= arr->size) { array_resize(arr); }

	array_set(arr, item, arr->count);
	arr->count += 1;
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
	if (arr->count > 0)
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
	if (arr->size <= arr->count) { array_resize(arr); }

	if (index >= arr->count) { array_push(arr, item); }
	else
	{
		int i = arr->count;
		for (; i >= index; i--) { array_set(arr, arr->items[i - 1], i); }
		array_set(arr, item, index - 1);
		arr->count += 1;
	}
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
 * Delete the array and free the used memory
 */
void array_free(array *arr)
{
	if (arr)
	{
		array_reset(arr);

		free(arr->items);
		free(arr);
	}
}

/**
 * Reset the array to the default state
 */
void array_reset(array *arr)
{
	arr->count = 0;
	arr->items = NULL;
}

#endif
