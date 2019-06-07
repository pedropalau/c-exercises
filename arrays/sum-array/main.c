// This exercise makes a sum of all the numbers
// inserted by the user using arrays

#include <stdio.h>

#include "../../utils/colors.c"

int main()
{
	int i, sum = 0, total = 0;

	print_color_green();
	printf("Sum numbers in array");
	print_color_reset();
	printf("\n");

	print_color_yellow();
	printf("Enter the total of numbers to sum: ");
	print_color_reset();

	// Wait for the user input
	do
	{
		(void) (scanf("%d", &total) + 1);
		if (total < 0)
		{
			print_color_red();
			printf("Invalid array size entered\n");
			print_color_reset();
		}
	} while (total < 0);

	// Ask user for each number of the list
	int numbers[total];
	for (i = 0; i < total; i++)
	{
		printf("Enter number %d: ", i + 1);

		// Take the input number entered by the user
		// and insert it in `i` element
		(void) (scanf("%d", &numbers[i]));
		sum += numbers[i];
	}

	print_color_yellow();
	printf("Numbers you entered:");
	print_color_reset();
	printf(" [");

	for (i = 0; i < total; i++)
	{
		if (i < total - 1) { printf("%d, ", numbers[i]); }
		else
		{
			printf("%d", numbers[i]);
		}
	}
	printf("]\n");

	print_color_green();
	printf("Sum:");
	print_color_reset();
	printf(" %d\n", sum);

	return 0;
}
