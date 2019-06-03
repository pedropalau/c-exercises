#define C_UTILS_COLORS

#include "../constants.h"

static void print_color(char *color)
{
	printf("%s", color);
}

void print_color_blue()
{
	print_color(COLOR_BLUE);
}

void print_color_red()
{
	print_color(COLOR_RED);
}

void print_color_green()
{
	print_color(COLOR_GREEN);
}

void print_color_yellow()
{
	print_color(COLOR_YELLOW);
}

void print_color_reset()
{
	printf(COLOR_RESET);
}
