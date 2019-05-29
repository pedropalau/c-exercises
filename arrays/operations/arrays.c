// This is a basic exercise for working with 
// arrays and making some operations like pop, push or shift.

#include <stdio.h>

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

void print_options()
{
    printf("\n");
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

void print_options_error()
{
    printf("\n");
    printf(COLOR_RED "Select a valid option" COLOR_RESET "\n");
}

int main(int argc, char const *argv[])
{
    int MIN_OPTION = OPTION_1
      , MAX_OPTION = OPTION_9
      , selected = MIN_OPTION - 1;

    printf(COLOR_GREEN "/ ---------------------- /" COLOR_RESET "\n");
    printf(COLOR_GREEN "  BASIC ARRAY OPERATIONS  " COLOR_RESET "\n");
    printf(COLOR_GREEN "/ ---------------------- /" COLOR_RESET "\n");

    print_options();

    scanf("%d", &selected);

    while (selected < MIN_OPTION || selected > MAX_OPTION)
    {
        print_options_error();

        print_options();

        scanf("%d", &selected);
    }
    
    switch (selected)
    {

        case OPTION_2:
          printf("Option 2\n");
          break;

        case OPTION_3:
          printf("Option 3\n");
          break;

        case OPTION_4:
          printf("Option 4\n");
          break;

        case OPTION_5:
          printf("Option 5\n");
          break;

        case OPTION_6:
          printf("Option 6\n");
          break;

        case OPTION_7:
          printf("Option 7\n");
          break;

        case OPTION_8:
          printf("Option 8\n");
          break;

        case OPTION_9:
          printf("Option 9\n");
          break;
        
        default:
          printf("Option 1\n");
          break;
    }

    return 0;
}
