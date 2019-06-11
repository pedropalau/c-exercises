#ifndef C_ARRAY_EDITOR

#define C_ARRAY_EDITOR

#include <stdarg.h>

#include "../../constants.h"

#include "editor.h"
#include "helpers.c"
#include "utils.c"

/**
 * Print the program options
 */
void print_options()
{
	print_new_line();

	print_color_yellow();
	printf_tabbed("Options:\n\n");
	print_color_reset();

	printf_tabbed("[ %d ] Create\n", OPTION_CREATE);
	printf_tabbed("[ %d ] Push\n", OPTION_PUSH);
	printf_tabbed("[ %d ] Pop\n", OPTION_POP);
	printf_tabbed("[ %d ] Shift\n", OPTION_SHIFT);
	printf_tabbed("[ %d ] Insert\n", OPTION_INSERT);
	printf_tabbed("[ %d ] Search\n", OPTION_SEARCH);
	printf_tabbed("[ %d ] Product\n", OPTION_PRODUCT);
	printf_tabbed("[ %d ] Count\n", OPTION_COUNT);
	printf_tabbed("[ %d ] Exit\n", OPTION_EXIT);

	print_new_line();

	printf_tabbed("Select an option: ");
}

/**
 * Print a custom title
 */
void printf_title(char *message, int option)
{
	print_color_green();
	printf_tabbed("%d. %s", option, message);
	print_color_reset();
	printf("\n\n");
}

/**
 * Print an error
 */
void printf_error(char *message, bool space)
{
	if (space) { print_new_line(); }

	print_color_red();
	printf_tabbed("Error: %s", message);
	print_color_reset();
	print_new_line();
}

/**
 * Print a success message
 */
void printf_success(char *message, bool space)
{
	if (space) { print_new_line(); }

	print_color_green();
	printf_tabbed("Success: %s", message);
	print_color_reset();
	print_new_line();
}

/**
 * Print the specified text with tab space
 */
void printf_tabbed(const char *text, ...)
{
	va_list args;
	va_start(args, text);
	print_space();
	(void) (vprintf(text, args));
	va_end(args);
}

/**
 * Print an error when an incorrect option is selected
 */
void print_options_error()
{
	printf_error("Invalid option selected", true);
}

// @group Array printing related functions
// ======================================================================
void print_array_length(array *arr)
{
	print_array_start(arr);
	print_array_fields(arr);
	print_new_line();
	print_label("Length", arr);
	print_value(arr->count, arr, true);
}

void print_array_size(array *arr)
{
	print_array_middle(arr);
	print_array_fields(arr);
	print_new_line();
	print_label("Size", arr);
	print_value((int) arr->size, arr, true);
}

void print_array_indexes(array *arr)
{
	print_array_middle(arr);
	print_array_slots(arr);
	print_new_line();
	print_label("Indexes", arr);
	print_indexes(arr);
}

void print_array_elements(array *arr)
{
	print_array_middle(arr);
	print_array_slots(arr);
	print_new_line();
	print_label("Elements", arr);
	print_elements(arr);
}

/**
 * This function print the following structure:
 * +------------------------------+
 * | Length       | 10            |
 * +------------------------------+
 * | Size         | 10            |
 * +------------------------------+
 * | Indexes      | 0 | 1 | 2 | 3 |
 * +------------------------------+
 * | Elements     | 1 | 2 | 3 | 4 |
 * +------------------------------+
 */
void print_array(array *arr)
{
	print_array_length(arr);
	print_new_line();
	print_array_size(arr);
	print_new_line();
	print_array_indexes(arr);
	print_new_line();
	print_array_elements(arr);
	print_new_line();
	print_array_end(arr);
	print_array_slots(arr);
	print_new_line();
}

// ======================================================================

/**
 * Print a new line on the terminal
 */
void print_new_line()
{
	printf("%s", NEW_LINE);
}

/**
 * Do an `space` printing on terminal
 */
static void print_space()
{
	printf("%s", TAB_SIZE);
}

/**
 * Simulate an `hr` printing on the terminal
 */
void print_hr()
{
	printf("----------------------------------");
}

#endif
