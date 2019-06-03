#ifndef C_ARRAY_EDITOR_H

#define C_ARRAY_EDITOR_H

#include "arrays.h"

#define OPTION_CREATE 1
#define OPTION_PUSH 2
#define OPTION_POP 3
#define OPTION_SHIFT 4
#define OPTION_INSERT 5
#define OPTION_SEARCH 6
#define OPTION_PRODUCT 7
#define OPTION_COUNT 8
#define OPTION_EXIT 9

/**
 * Print the program options
 */
void print_options();

/**
 * Print a custom title on the terminal
 */
void printf_title(char *message, int option);

/**
 * Print an error 
 */
void printf_error(char *message, bool space);

/**
 * Print a success message
 */
void printf_success(char *message, bool space);

/**
 * Print the specified text with tab space
 */
void printf_tabbed(const char *text, ...);

/**
 * Print an error when an incorrect option is selected
 */
void print_options_error();

/**
 * Helper function for printing an array
 */
void print_array(array *arr);

/**
 * Print a new line on the terminal
 */
void print_new_line();

/**
 * Do an `space` printing on terminal
 */
void print_space();

/**
 * Simulate an `hr` printing on the terminal
 */
void print_hr();

#endif
