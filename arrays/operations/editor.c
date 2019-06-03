#ifndef C_ARRAY_EDITOR

#define C_ARRAY_EDITOR

#include "../../constants.h"

#include "editor.h"

#include "utils.c"

/**
 * Print the program options 
 */
void print_options()
{
    printf("\n");

    print_color_yellow();
    printf(TAB_SIZE "Options:\n\n");
    print_color_reset();

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
 * Print a custom title
 */
void printf_title(char *message, int option)
{   
    print_color_green();
    printf(TAB_SIZE "%d. %s", option, message);
    print_color_reset();
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
    
    print_color_red();
    printf(TAB_SIZE "Error: %s", message);
    print_color_reset();
    printf("\n");
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

    print_color_green();
    printf(TAB_SIZE "Success: %s", message);
    print_color_reset();
    printf("\n");
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
        if (arr->count > 0)
        {
            print_color_yellow();
        }
        else
        {
            print_color_red();
        }
        printf("%d", arr->count);
        print_color_reset();
        printf(" |\n");

        printf(TAB_SIZE "%s%s%s\n", append, size_repeat, string);
        printf(TAB_SIZE "| Size      | ");
        if (arr->size > arr->count)
        {
            print_color_yellow();
        }
        else
        {
            print_color_red();
        }
        printf("%d", arr->size);
        print_color_reset();
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
            print_color_red();
            printf("x");
            print_color_reset();
            printf( " |");
        }

        for (i = 0; i < arr->count; i++)
        {
            print_color_yellow();
            printf("%d", arr->items[i]);
            print_color_reset();
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

#endif
