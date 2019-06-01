#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper function for repeating a character
 * specific number of times
 */
char *repeat_str(const char *string, int size)
{
    if (size == 0)
    {
        return NULL;
    }

    char *result = malloc(strlen(string) * size + size);

    if (result == NULL)
    {
        return NULL;
    }

    strcpy(result, string);
    while (--size > 0) 
    {
        strcat(result, string);
    }

    return result;
}

/**
 * This function count digits on a number
 */
int count_digits(int number)
{
    int count = 0;
    int n = number ? number : 0;

    while (n > 0)
    {
        n /= 10;
        count++;
    }

    return number == 0 ? 1 : count;
}
