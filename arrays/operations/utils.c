#ifndef C_ARRAY_UTILS

#define C_ARRAY_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/**
 * Helper function for repeating a character
 * specific number of times
 */
/*@notnull@*/ char *repeat_str(const char *string, int size)
{
	char *result = NULL;
	do
	{
		result = malloc(strlen(string) * size + size);
	} while (result == NULL);

	strcpy(result, string);
	while (--size > 0) { strcat(result, string); }

	return result;
}

/**
 * This function count digits on a number
 */
int count_digits(int number)
{
	int count = 0;
	int n = number;

	while (n > 0)
	{
		n /= 10;
		count++;
	}

	return number == 0 ? 1 : count;
}

#endif
