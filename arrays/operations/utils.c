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
/*@notnull@*/ char *repeat_str(char *string, int size)
{
	char *pa, *pb;
	size_t length = strlen(string);
	char *destination = NULL;
	do
	{
		destination = malloc(size * length + 1);
	} while (destination == NULL);
	pa = destination + (size - 1) * length;
	strcpy(pa, string);
	pb = --pa + length;
	while (pa >= destination) *pa-- = *pb--;
	return destination;
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

/**
 * This function count the number of chars in string
 */
int count_chars(const char *string)
{
	return (int) strlen(string);
}

/**
 * Join two strings
 */
void join_str(char *str1, char *str2)
{
	char string1[strlen(str1)];
	char string2[strlen(str2)];

	strcpy(string1, str1);
	strcpy(string2, str2);

	strcat(string1, string2);
}

#endif
