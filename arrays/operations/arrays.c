// This is a basic exercise for working with 
// arrays and making some operations like pop, push or shift.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrays.h"

#define ARRAY_SIZE      10

#define COLOR_GREEN     "\x1b[32m"
#define COLOR_YELLOW    "\x1b[33m"
#define COLOR_RED       "\x1b[31m"
#define COLOR_BLUE      "\x1b[34m"
#define COLOR_RESET     "\x1b[0m"

#define TAB_SIZE        "  "
#define CHAR_REPEAT     "-"

#define OPTION_1        1
#define OPTION_2        2
#define OPTION_3        3
#define OPTION_4        4
#define OPTION_5        5
#define OPTION_6        6
#define OPTION_7        7
#define OPTION_8        8
#define OPTION_9        9

#define ARRAY_MIN_SIZE  1
#define ARRAY_MAX_SIZE  10

/**
 * Print the program options 
 */
void print_options()
{
    printf("\n");
    printf(TAB_SIZE COLOR_YELLOW "Options:\n\n" COLOR_RESET);
    printf("%s[ %d ] Create\n",  TAB_SIZE, OPTION_1);
    printf("%s[ %d ] Push\n",    TAB_SIZE, OPTION_2);
    printf("%s[ %d ] Pop\n",     TAB_SIZE, OPTION_3);
    printf("%s[ %d ] Shift\n",   TAB_SIZE, OPTION_4);
    printf("%s[ %d ] Insert\n",  TAB_SIZE, OPTION_5);
    printf("%s[ %d ] Search\n",  TAB_SIZE, OPTION_6);
    printf("%s[ %d ] Product\n", TAB_SIZE, OPTION_7);
    printf("%s[ %d ] Count\n",   TAB_SIZE, OPTION_8);
    printf("%s[ %d ] Exit\n",    TAB_SIZE, OPTION_9);
    printf("\n");
    printf(TAB_SIZE "Select an option: ");
}

/**
 * Helper function for repeating a char
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

/**
 * Print a custom title
 */
void printf_title(char *message, int option)
{   
    printf(COLOR_GREEN);
    printf(TAB_SIZE "%d. %s", option, message);
    printf(COLOR_RESET);
    printf("\n\n");
}

/**
 * Print an error 
 */
void printf_error(char *message, bool space)
{
    if (space)
    {
        printf("\n");
    }
    printf(TAB_SIZE COLOR_RED "Error: %s" COLOR_RESET "\n", message);
}

/**
 * Print a success message
 */
void printf_success(char *message, bool space)
{
    if (space)
    {
        printf("\n");
    }
    printf(TAB_SIZE COLOR_GREEN "Success: %s" COLOR_RESET "\n", message);
}

/**
 * Print an error when an incorrect option is selected
 */
void print_options_error()
{
    printf_error("Invalid option selected", true);
}

/**
 * Helper function for printing an array
 */
void print_array(array *arr)
{
    if (arr)
    {
        int i;
        const char *append = repeat_str(CHAR_REPEAT, 11);
        const char *offset = repeat_str(CHAR_REPEAT, 2);
        const char *string = repeat_str(CHAR_REPEAT, 5);

        const char *count_repeat = repeat_str(CHAR_REPEAT, count_digits(arr->count));
        const char *size_repeat = repeat_str(CHAR_REPEAT, count_digits(arr->size));

        printf(TAB_SIZE "%s%s%s\n", append, count_repeat, string);
        printf(TAB_SIZE "| Length    | ");
        printf(arr->count > 0 ? COLOR_YELLOW : COLOR_RED);
        printf("%d", arr->count);
        printf(COLOR_RESET);
        printf(" |\n");

        printf(TAB_SIZE "%s%s%s\n", append, size_repeat, string);
        printf(TAB_SIZE "| Size      | ");
        printf(arr->size > arr->count ? COLOR_YELLOW : COLOR_RED);
        printf("%d", arr->size);
        printf(COLOR_RESET);
        printf(" |\n");

        printf(TAB_SIZE "%s%s", append, offset);

        // Print the repeater char based on the digits
        if (arr->count > 0)
        {
            for (i = 0; i < arr->count; i++)
            {
                const char *__append = repeat_str(CHAR_REPEAT, count_digits(arr->items[i]) + 3);
                printf("%s", __append);
                free((char*) __append);
            }
        }
        else
        {
            const char *__append = repeat_str(CHAR_REPEAT, 4);
            printf("%s", __append);
            free((char*) __append);
        }

        printf("\n" TAB_SIZE "| Elements  | ");

        if (arr->count == 0)
        {
            printf(COLOR_RED "x" COLOR_RESET " |");
        }

        for (i = 0; i < arr->count; i++)
        {
            printf(COLOR_YELLOW);
            printf("%d", arr->items[i]);
            printf(COLOR_RESET);
            printf(" | ");
        }

        printf("\n" TAB_SIZE "%s%s", append, offset);

        if (arr->count > 0)
        {
            for (i = 0; i < arr->count; i++)
            {
                int count = count_digits(arr->items[i]);
                const char *__append = repeat_str(CHAR_REPEAT, count + 3);
                printf("%s", __append);
                free((char*) __append);
            }
        }
        else
        {
            const char *__append = repeat_str(CHAR_REPEAT, 4);
            printf("%s", __append);
            free((char*) __append);
        }

        free((char*) append);
        free((char*) offset);
        free((char*) string);
        free((char*) count_repeat);

        printf("\n");
    }
    else
    {
        printf_error("Invalid array", true);
    }
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

/**
 * Option callback: create an array with an specific size
 */
array *option_create_array()
{
    int size, element, index = 0;

    printf_title("Create array", OPTION_1);

    printf(TAB_SIZE "Insert the size of the array (value between 1 - 10): ");

    scanf("%d", &size);

    if (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
    {
        while (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
        {
            printf_error("Invalid size, please enter again", false);
            printf(TAB_SIZE "Insert the size of the array (value between 1 - 10): ");
            scanf("%d", &size);
        }
    }

    array *arr = array_create(size);

    if (arr)
    {
        // Fill the array with entry values
        for (; index < size; index++)
        {
            printf(TAB_SIZE COLOR_BLUE " => " COLOR_RESET "Enter element ");
            printf(COLOR_YELLOW);
            printf("#%d: ", index + 1);
            printf(COLOR_RESET);
            scanf("%d", &element);
            array_set(arr, element, index);
        }

        printf_success("Array created", true);
        printf("\n");
    }

    return arr;
}

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
 * Push an element to the end of the array
 */
void option_push_array(array *arr)
{
    int number;

    printf_title("Push", OPTION_2);
    printf(TAB_SIZE "Type the element to push: ");
    scanf("%d", &number);
    printf("\n");
    array_push(arr, number);
}

void array_push(array *arr, int item)
{
    array_set(arr, item, arr->count);
    arr->count += 1;
}

void array_set(array *arr, int item, int index)
{
    // @TODO resize the array if required
    arr->items[index] = item;
}

/**
 * Pop an element from end of the array
 */
int option_pop_array(array *arr)
{
    printf_title("Pop", OPTION_3);
    int last = array_pop(arr);
    return last;
}

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

/**
 * Remove the first element from the array
 */
void option_shift_array()
{
    printf("Option 4\n");
}

/**
 * Insert an element onto the array
 */
void option_insert_array()
{
    printf("Option 5\n");
}

/**
 * Search an element on the array
 */
void option_search_array()
{
    printf("Option 6\n");
}

/**
 * Calculate the product of elements of the array
 */
void option_product_array()
{
    printf("Option 7\n");
}

/**
 * Count all elements from the array
 */
void option_count_array()
{
    printf("Option 8\n");
}

/**
 * The main program
 */
int main(int argc, char const *argv[])
{
    int MIN_OPTION = OPTION_1,
        MAX_OPTION = OPTION_9,
        EXIT_OPTION = MAX_OPTION,
        selected = MIN_OPTION - 1,
        last_item;

    array *arr = array_create(0);

    printf(TAB_SIZE COLOR_GREEN "----------------------------------" COLOR_RESET "\n");
    printf(TAB_SIZE COLOR_GREEN "|       BASIC ARRAY OPERATIONS   |" COLOR_RESET "\n");
    printf(TAB_SIZE COLOR_GREEN "----------------------------------" COLOR_RESET "\n");

    print_options();

    scanf("%d", &selected);

    while (selected != EXIT_OPTION)
    {
        if (selected < MIN_OPTION || selected > MAX_OPTION)
        {
            print_options_error();
        }

        if (selected >= MIN_OPTION && selected <= MAX_OPTION && selected != EXIT_OPTION)
        {
            printf("\n");

            switch (selected)
            {
                case OPTION_2:
                    if (arr->count > 0)
                    {
                        option_push_array(arr);
                        print_array(arr);
                    }
                    else
                    {
                        printf_error("Please, create an array", false);
                    }
                    break;

                case OPTION_3:
                    if (arr->count > 0)
                    {
                        last_item = option_pop_array(arr);
                        printf(TAB_SIZE "Last item: %d\n\n", last_item);
                    }
                    else
                    {
                        printf_error("The array is empty\n", false);
                    }
                    print_array(arr);
                    break;

                case OPTION_4:
                    option_shift_array();
                    break;

                case OPTION_5:
                    option_insert_array();
                    break;

                case OPTION_6:
                    option_search_array();
                    break;

                case OPTION_7:
                    option_product_array();
                    break;

                case OPTION_8:
                    option_count_array();
                    break;

                default:
                    arr = option_create_array();
                    print_array(arr);
                    break;
            }
        }

        print_options();
        scanf("%d", &selected);
    }

    array_free(arr);
    printf_success("Exiting program", true);

    return 0;
}
