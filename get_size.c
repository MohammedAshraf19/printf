#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string.
 * @i: List of arguments.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = ST_LONG;
	else if (format[curr_i] == 'h')
		size = ST_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
