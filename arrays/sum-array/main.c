// This exercise makes a sum of all the numbers
// inserted by the user using arrays

#include <stdio.h>

#include "../../utils/colors.c"

int main(int argc, char const *argv[])
{
	int i, j, total, sum = 0;

	print_color_green();
	printf("Sum numbers in array");
	print_color_reset();
	printf("\n");

	print_color_yellow();
	printf("Enter the total of numbers to sum: ");
	print_color_reset();

	// Wait for the user input
	scanf("%d", &total);

	// Ask user for each number of the list
	int numbers[total];
	for (i = 0; i < total; i++)
	{
		printf("Enter number %d: ", i + 1);

		// Take the input number entered by the user
		// and insert it in `i` element
		scanf("%d", &numbers[i]);
		sum += numbers[i];
	}

	print_color_yellow();
	printf("Numbers you entered:");
	print_color_reset();
	printf(" [");

	for (j = 0; j < total; j++)
	{
		if (j < total - 1) { printf("%d, ", numbers[j]); }
		else
		{
			// The last number of the list
			printf("%d", numbers[j]);
		}
	}
	printf("]\n");

	print_color_green();
	printf("Sum:");
	print_color_reset();
	printf(" %d\n", sum);

	return 0;
}
