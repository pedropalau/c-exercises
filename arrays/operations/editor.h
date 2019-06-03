#ifndef C_ARRAY_EDITOR_H

#define C_ARRAY_EDITOR_H

#include "arrays.h"

#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3
#define OPTION_4 4
#define OPTION_5 5
#define OPTION_6 6
#define OPTION_7 7
#define OPTION_8 8
#define OPTION_9 9

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
 * Print an error when an incorrect option is selected
 */
void print_options_error();

/**
 * Helper function for printing an array
 */
void print_array(array *arr);

#endif
