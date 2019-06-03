// This is a basic exercise for working with 
// arrays and making some operations like pop, push or shift.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../constants.h"
#include "../../utils/colors.c"

#include "arrays.c"
#include "editor.c"
#include "utils.c"

/**
 * Option callback: create an array with an specific size
 */
array *option_create_array()
{
    int size, element, index = 0;

    printf_title("Create array", OPTION_CREATE);

    printf_tabbed("Insert the size of the array (value between 1 - 10): ");

    scanf("%d", &size);

    if (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
    {
        while (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
        {
            printf_error("Invalid size, please enter again", false);
            printf_tabbed("Insert the size of the array (value between 1 - 10): ");
            scanf("%d", &size);
        }
    }

    array *arr = array_create(size);

    if (arr)
    {
        // Fill the array with entry values
        for (; index < size; index++)
        {
            print_space();
            print_color_blue();
            printf(" => ");
            print_color_reset();
            printf("Enter element ");
            print_color_yellow();
            printf("#%d: ", index + 1);
            print_color_reset();
            scanf("%d", &element);
            array_set(arr, element, index);
        }

        printf_success("Array created", true);
        print_new_line();
    }

    return arr;
}

/**
 * Push an element to the end of the array
 */
void option_push_array(array *arr)
{
    int number;

    printf_title("Push", OPTION_PUSH);
    printf_tabbed("Type the element to push: ");
    scanf("%d", &number);
    print_new_line();
    array_push(arr, number);
}

/**
 * Pop an element from end of the array
 */
int option_pop_array(array *arr)
{
    printf_title("Pop", OPTION_POP);
    int last = array_pop(arr);
    return last;
}

/**
 * Remove the first element from the array
 */
int option_shift_array(array *arr)
{
    printf_title("Shift", OPTION_SHIFT);
    int first = array_shift(arr);
    return first;
}

/**
 * Insert an element onto the array
 */
void option_insert_array(array *arr)
{
    int number, position = -1;

    printf_title("Insert", OPTION_INSERT);

    printf_tabbed("Type element to insert: ");
    scanf("%d", &number);

    while (position < 0 || position > arr->count + 1)
    {
        printf_tabbed("Type the position where to insert: ");
        scanf("%d", &position);
        if (position < 0 || position > arr->count + 1)
        {
            printf_error("Please insert a position between 0 to [total]", false);
        }
    }

    print_new_line();

    array_insert(arr, number, position);
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
    int MIN_OPTION = OPTION_CREATE,
        MAX_OPTION = OPTION_EXIT,
        EXIT_OPTION = MAX_OPTION,
        selected = MIN_OPTION - 1,
        last_item, first_item;

    array *arr = array_create(0);

    print_space();
    print_color_green();
    print_hr();
    print_color_reset();
    print_new_line();

    print_space();
    print_color_green();
    printf("|       BASIC ARRAY OPERATIONS   |");
    print_color_reset();
    print_new_line();

    print_space();
    print_color_green();
    print_hr();
    print_color_reset();
    print_new_line();

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
            print_new_line();

            switch (selected)
            {
                case OPTION_PUSH:
                    option_push_array(arr);
                    print_array(arr);
                    break;

                case OPTION_POP:
                    if (arr->count > 0)
                    {
                        last_item = option_pop_array(arr);
                        printf_tabbed("Last item: %d\n\n", last_item);
                    }
                    else
                    {
                        printf_error("The array is empty\n", false);
                    }
                    print_array(arr);
                    break;

                case OPTION_SHIFT:
                    if (arr->count > 0)
                    {
                        first_item = option_shift_array(arr);
                        printf_tabbed("First item: %d\n\n", first_item);
                    }
                    else
                    {
                        printf_error("The array is empty\n", false);
                    }
                    print_array(arr);
                    break;

                case OPTION_INSERT:
                    option_insert_array(arr);
                    print_array(arr);
                    break;

                case OPTION_SEARCH:
                    option_search_array();
                    break;

                case OPTION_PRODUCT:
                    option_product_array();
                    break;

                case OPTION_COUNT:
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
