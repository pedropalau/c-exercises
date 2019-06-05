#ifndef C_ARRAY_EDITOR

#define C_ARRAY_EDITOR

#include <stdarg.h>

#include "../../constants.h"

#include "editor.h"

#include "utils.c"

/**
 * Print the program options
 */
void print_options() {
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
void printf_title(char *message, int option) {
  print_color_green();
  printf_tabbed("%d. %s", option, message);
  print_color_reset();
  printf("\n\n");
}

/**
 * Print an error
 */
void printf_error(char *message, bool space) {
  if (space) {
    print_new_line();
  }

  print_color_red();
  printf_tabbed("Error: %s", message);
  print_color_reset();
  print_new_line();
}

/**
 * Print a success message
 */
void printf_success(char *message, bool space) {
  if (space) {
    print_new_line();
  }

  print_color_green();
  printf_tabbed("Success: %s", message);
  print_color_reset();
  print_new_line();
}

/**
 * Print the specified text with tab space
 */
void printf_tabbed(const char *text, ...) {
  va_list args;
  va_start(args, text);
  print_space();
  vprintf(text, args);
  va_end(args);
}

/**
 * Print an error when an incorrect option is selected
 */
void print_options_error() { printf_error("Invalid option selected", true); }

/**
 * Helper function for printing an array
 */
void print_array(array *arr) {
  if (arr) {
    int i;
    const char *append = repeat_str(CHAR_REPEAT, 11);
    const char *offset = repeat_str(CHAR_REPEAT, 2);
    const char *string = repeat_str(CHAR_REPEAT, 5);

    const char *count_repeat =
        repeat_str(CHAR_REPEAT, count_digits(arr->count));
    const char *size_repeat = repeat_str(CHAR_REPEAT, count_digits(arr->size));

    printf_tabbed("%s%s%s\n", append, count_repeat, string);
    printf_tabbed("| Length    | ");
    if (arr->count > 0) {
      print_color_yellow();
    } else {
      print_color_red();
    }
    printf("%d", arr->count);
    print_color_reset();
    printf(" |\n");

    printf_tabbed("%s%s%s\n", append, size_repeat, string);
    printf_tabbed("| Size      | ");
    if (arr->size > arr->count) {
      print_color_yellow();
    } else {
      print_color_red();
    }
    printf("%d", arr->size);
    print_color_reset();
    printf(" |\n");

    printf_tabbed("%s%s", append, offset);

    // Print the repeater char based on the digits
    if (arr->count > 0) {
      for (i = 0; i < arr->count; i++) {
        const char *__append =
            repeat_str(CHAR_REPEAT, count_digits(arr->items[i]) + 3);
        printf("%s", __append);
        free((char *)__append);
      }
    } else {
      const char *__append = repeat_str(CHAR_REPEAT, 4);
      printf("%s", __append);
      free((char *)__append);
    }

    print_new_line();
    printf_tabbed("| Elements  | ");

    if (arr->count == 0) {
      print_color_red();
      printf("x");
      print_color_reset();
      printf(" |");
    }

    for (i = 0; i < arr->count; i++) {
      print_color_yellow();
      printf("%d", arr->items[i]);
      print_color_reset();
      printf(" | ");
    }

    print_new_line();
    printf_tabbed("%s%s", append, offset);

    if (arr->count > 0) {
      for (i = 0; i < arr->count; i++) {
        int count = count_digits(arr->items[i]);
        const char *__append = repeat_str(CHAR_REPEAT, count + 3);
        printf("%s", __append);
        free((char *)__append);
      }
    } else {
      const char *__append = repeat_str(CHAR_REPEAT, 4);
      printf("%s", __append);
      free((char *)__append);
    }

    free((char *)append);
    free((char *)offset);
    free((char *)string);
    free((char *)count_repeat);

    print_new_line();
  } else {
    printf_error("Invalid array", true);
  }
}

/**
 * Print a new line on the terminal
 */
void print_new_line() { printf("%s", NEW_LINE); }

/**
 * Do an `space` printing on terminal
 */
void print_space() { printf("%s", TAB_SIZE); }

/**
 * Simulate an `hr` printing on the terminal
 */
void print_hr() { printf("----------------------------------"); }

#endif
