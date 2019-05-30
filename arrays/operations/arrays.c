// This is a basic exercise for working with 
// arrays and making some operations like pop, push or shift.

#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

#define COLOR_GREEN  "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_RESET  "\x1b[0m"

#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3
#define OPTION_4 4
#define OPTION_5 5
#define OPTION_6 6
#define OPTION_7 7
#define OPTION_8 8
#define OPTION_9 9

#define ARRAY_MIN_SIZE 1
#define ARRAY_MAX_SIZE 10

/**
 * Print the program options 
 */
void print_options()
{
    printf("\n");
    printf(COLOR_YELLOW "Options:\n\n" COLOR_RESET);
    printf("%d. Create\n",  OPTION_1);
    printf("%d. Push\n",    OPTION_2);
    printf("%d. Pop\n",     OPTION_3);
    printf("%d. Shift\n",   OPTION_4);
    printf("%d. Insert\n",  OPTION_5);
    printf("%d. Search\n",  OPTION_6);
    printf("%d. Product\n", OPTION_7);
    printf("%d. Count\n",   OPTION_8);
    printf("%d. Exit\n",    OPTION_9);
    printf("\n");
    printf("Select an option: ");
}

/**
 * Print a custom title
 */
void printf_title(char *message, int option)
{   
    printf(COLOR_GREEN);
    printf("%d. %s", option, message);
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
    printf(COLOR_RED "Error: %s" COLOR_RESET "\n", message);
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
    printf(COLOR_GREEN "Success: %s" COLOR_RESET "\n", message);
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
    
        printf("Length: %d \n", arr->count);
        printf("Elements: [");
        
        for (i = 0; i < arr->count; i++)
        {
            printf("%d", arr->items[i]);
            if (i < arr->count - 1)
            {
                printf(",");
            }
        }
        printf("]\n");
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
        free(arr->items);
        free(arr);
    }
}

/**
 * Option callback: create an array with an specific size
 */
array *option_create_array()
{
    int size, element, index = 0;

    printf_title("Create", OPTION_1);

    printf("Insert the size of the array (value between 1 - 10): ");

    scanf("%d", &size);

    if (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
    {
        while (size < ARRAY_MIN_SIZE || size > ARRAY_MAX_SIZE)
        {
            printf_error("Invalid size, please enter again", false);

            printf("Insert the size of the array (value between 1 - 10): ");

            scanf("%d", &size);

        }
    }

    array *arr = array_create(size);

    if (arr)
    {
        // Fill the array with entry values
        for (index; index < size; index++)
        {
            printf("Enter element # %d: ", index + 1);
            scanf("%d", &element);
            array_set(arr, element, index);
        }

        printf_success("Array created", true);
        printf("\n");
    }

    return arr;
}

array *array_create(int size)
{
    array *arr = (array *) malloc(sizeof(array));

    if (arr)
    {
        arr->count = size;
        arr->items = malloc(size * sizeof(int));
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

    printf("Type the element to push: ");

    scanf("%d", &number);

    array_push(arr, number);
}

void array_push(array *arr, int item)
{
    arr->items[arr->count] = item;
    arr->count++;
}

void array_set(array *arr, int item, int index)
{
    arr->items[index] = item;
}

/**
 * Pop an element from end of the array
 */
void option_pop_array()
{
    printf("Option 3\n");
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
    int MIN_OPTION = OPTION_1
      , MAX_OPTION = OPTION_9
      , EXIT_OPTION = MAX_OPTION
      , selected = MIN_OPTION - 1;

    array *arr;

    printf(COLOR_GREEN "/ ---------------------- /" COLOR_RESET "\n");
    printf(COLOR_GREEN "  BASIC ARRAY OPERATIONS  " COLOR_RESET "\n");
    printf(COLOR_GREEN "/ ---------------------- /" COLOR_RESET "\n");

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
                  option_push_array(arr);
                  print_array(arr);
                  break;

                case OPTION_3:
                  option_pop_array();
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

    return 0;
}
