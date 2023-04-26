#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags.
 */

int get_flags(const char *format, int *i)
{
	int j, curr_i;

	int result = 0;

	char flag_ch[] = {'-', '+', '0', '#', ' ', '\0'};

	int flags_ar[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; flag_ch[j] != '\0'; j++)

		if (format[curr_i] == flag_ch[j])
		{
			result |= flags_ar[j];
			break;
		}

		if (flag_ch[j] == 0)

			break;
	}

	*i = curr_i - 1;

	return (result);
}
