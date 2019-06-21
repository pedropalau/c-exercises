#ifndef C_ARRAY_HELPERS

#define C_ARRAY_HELPERS

#include "../../constants.h"

#include "helpers.h"
#include "utils.c"

void print_array_divider_values(array *arr)
{
	int i = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			r = repeat_str(CHAR_NORMAL, count_digits(arr->items[i]));
			printf("%s", r);
			free(r);
		}
	}
}

static void print_array_line(/*@unused@*/ array *arr)
{
	char *line = repeat_str(CHAR_NORMAL, LABEL_COLUMN_SIZE - 1);
	printf("%s", line);
	free(line);
}

void print_array_fields(array *arr)
{
	int i = 0, n = 0, m = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			n = count_digits(arr->items[i]);
			m = count_digits(i);
			r = repeat_str(CHAR_NORMAL, (n > m ? n : m) + 3);
			printf("%s", r);
			free(r);
		}
		printf("%s", CHAR_CORNER);
	}
}

void print_array_slots(array *arr)
{
	int i = 0, n = 0, m = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			printf("%s", CHAR_CORNER);

			n = count_digits(arr->items[i]);
			m = count_digits(i);
			r = repeat_str(CHAR_NORMAL, (n > m ? n : m) + 2);
			printf("%s", r);
			free(r);
		}
		printf("%s", CHAR_CORNER);
	}
}

void print_array_start(array *arr)
{
	printf_tabbed("%s", CHAR_CORNER);
	print_array_line(arr);
}

void print_array_middle(array *arr)
{
	printf_tabbed("%s", CHAR_CORNER);
	print_array_line(arr);
}

void print_label(char *label, /*@unused@*/ array *arr)
{
	char *spaces =
	  repeat_str(CHAR_SPACE, LABEL_COLUMN_SIZE - count_chars(label) - 2);
	printf_tabbed("%s", CHAR_DIVIDER);
	printf("%s%s", CHAR_SPACE, label);
	printf("%s", spaces);
	printf("%s", CHAR_DIVIDER);
	free(spaces);
}

static void print_offset(int value, array *arr)
{
	int i = 0, n = 0, m = 0, t = 0, x = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			n = count_digits(arr->items[i]);
			m = count_digits(i);
			t += (n > m ? n : m) + 3;
		}
	}

	x = count_digits(value) + 3;
	if (x < t) { r = repeat_str(CHAR_SPACE, t - x); }
	else if (x > t)
	{
		r = repeat_str(CHAR_SPACE, x - t);
	}
	if (r)
	{
		printf("%s", r);
		free(r);
	}
}

void print_value(int value, array *arr, bool offset)
{
	if (offset) { print_offset(value, arr); }
	printf("%s", CHAR_SPACE);
	print_color_yellow();
	printf("%d", value);
	print_color_reset();
	printf("%s", CHAR_SPACE);
	printf("%s", CHAR_DIVIDER);
}

void print_indexes(array *arr)
{
	int i = 0, n = 0, m = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			printf("%s", CHAR_SPACE);
			n = count_digits(arr->items[i]);
			m = count_digits(i);
			if (n > m)
			{
				r = repeat_str(CHAR_SPACE, n - m);
				printf("%s", r);
				free(r);
			}
			print_color_yellow();
			printf("%d", i);
			print_color_reset();
			printf("%s", CHAR_SPACE);
			printf("%s", CHAR_DIVIDER);
		}
	}
}

void print_elements(array *arr)
{
	int i = 0, n = 0, m = 0;
	char *r = NULL;
	if (arr != NULL && arr->items != NULL)
	{
		for (; i < arr->count; i++)
		{
			printf("%s", CHAR_SPACE);
			n = count_digits(arr->items[i]);
			m = count_digits(i);
			if (n < m)
			{
				r = repeat_str(CHAR_SPACE, m - n);
				printf("%s", r);
				free(r);
			}
			print_color_green();
			printf("%d", arr->items[i]);
			print_color_reset();
			printf("%s", CHAR_SPACE);
			printf("%s", CHAR_DIVIDER);
		}
	}
}

void print_array_end(array *arr)
{
	printf_tabbed("%s", CHAR_CORNER);
	print_array_line(arr);
}

#endif
