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
 * Validate if the array is initialized
 */
bool validate_array(array *arr)
{
	if (arr != NULL) { return true; }

	printf_error("The array is invalid", false);
	print_new_line();

	return true;
}

/**
 * Option callback: create an array with an specific size
 */
void option_create_array(array *arr)
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
			printf_tabbed("Insert the size of the array (value "
			              "between 1 - 10): ");
			scanf("%d", &size);
		}
	}

	arr = array_create(size);

	if (arr)
	{
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

		print_array(arr);
	}
	else
	{
		printf_error("There was an error while creating the array.", true);
	}
}

/**
 * Push an element to the end of the array
 */
void option_push_array(array *arr)
{
	if (validate_array(arr))
	{
		int number;

		printf_title("Push", OPTION_PUSH);

		printf_tabbed("Type the element to push: ");
		scanf("%d", &number);

		print_new_line();

		array_push(arr, number);

		print_array(arr);
	}
}

/**
 * Pop an element from end of the array
 */
void option_pop_array(array *arr)
{
	int last;

	printf_title("Pop", OPTION_SHIFT);

	if (arr->count > 0)
	{
		last = array_pop(arr);
		printf_tabbed("Last item: %d\n\n", last);
		print_array(arr);
	}
	else
	{
		printf_error("The array is empty\n", false);
	}
}

/**
 * Remove the first element from the array
 */
void option_shift_array(array *arr)
{
	int first;

	printf_title("Shift", OPTION_SHIFT);

	if (arr->count > 0)
	{
		first = array_shift(arr);
		printf_tabbed("First item: %d\n\n", first);
		print_array(arr);
	}
	else
	{
		printf_error("The array is empty\n", false);
	}
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
			printf_error("Please insert a position between 0 to [total]",
			             false);
		}
	}

	print_new_line();

	array_insert(arr, number, position);

	print_array(arr);
}

/**
 * Search an element on the array
 */
void option_search_array(array *arr)
{
	printf_title("Search", OPTION_SEARCH);
}

/**
 * Calculate the product of elements of the array
 */
void option_product_array(array *arr)
{
	printf_title("Product", OPTION_PRODUCT);
}

/**
 * Count all elements from the array
 */
void option_count_array(array *arr)
{
	printf_title("Count", OPTION_COUNT);
}

/**
 * Helper function to validate the selected option
 */
bool option_validate(int option)
{
	int size = 9, i = 0;

	int options[] = {OPTION_CREATE,  OPTION_PUSH,   OPTION_POP,
	                 OPTION_SHIFT,   OPTION_INSERT, OPTION_SEARCH,
	                 OPTION_PRODUCT, OPTION_COUNT,  OPTION_EXIT};

	for (; i < size; i++)
	{
		if (options[i] == option) { return true; }
	}

	return false;
}

/**
 * Helper function for printing the header
 * of the main program
 */
void print_main_header()
{
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
}

/**
 * Helper function that process the array
 * depending of the selected option
 */
void process_option(array *arr, int option)
{
	switch (option)
	{
		case OPTION_PUSH:
			option_push_array(arr);
			break;

		case OPTION_POP:
			option_pop_array(arr);
			break;

		case OPTION_SHIFT:
			option_shift_array(arr);
			break;

		case OPTION_INSERT:
			option_insert_array(arr);
			break;

		case OPTION_SEARCH:
			option_search_array(arr);
			break;

		case OPTION_PRODUCT:
			option_product_array(arr);
			break;

		case OPTION_COUNT:
			option_count_array(arr);
			break;

		default:
			option_create_array(arr);
			break;
	}
}

/**
 * The main program
 */
int main(int argc, char const *argv[])
{
	int selected;

	array *arr = NULL;

	print_main_header();

	do
	{
		print_options();

		scanf("%d", &selected);

		if (option_validate(selected) == false) { print_options_error(); }
		else if (selected != OPTION_EXIT)
		{
			print_new_line();

			process_option(arr, selected);

			print_array(arr);
		}
	} while (selected != OPTION_EXIT);

	if (arr != NULL) { array_free(arr); }

	printf_success("Exiting program", true);

	return 0;
}
