// This exercise makes a sum of all the numbers
// inserted by the user using arrays 

#include <stdio.h>

#define COLOR_GREEN  "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RESET  "\x1b[0m"

int main(int argc, char const *argv[])
{
    int i, j, total, sum = 0;

    printf(COLOR_GREEN "Summing numbers" COLOR_RESET "\n");

    printf(COLOR_YELLOW "Enter the total of numbers to sum: " COLOR_RESET);

    // Wait for the user input
    scanf("%d", &total);

    // Ask user for each number of the list
    int numbers[total];
    for (i = 0; i < total; i++) {
        printf("Enter number %d: ", i + 1);

        // Take the input number entered by the user
        // and insert it in `i` element
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf(COLOR_YELLOW "Numbers you entered:" COLOR_RESET " [");
    for (j = 0; j < total; j++) 
    {
        if (j < total - 1)
        {
            printf("%d, ", numbers[j]);
        }
        else
        {
            // The last number of the list
            printf("%d", numbers[j]);
        }
        
    }
    printf("]\n");

    printf(COLOR_GREEN "Sum:" COLOR_RESET " %d\n", sum);

    return 0;
}
