#include "main.h"
/**
* get_precision - Calculates the precision.
* @format: Formatted string/
* @i: List of arguments.
* @list: list of arguments.
* Return: integer.
 */

int get_precision(const char *format, int *i, va_list list)
{
		int curr_i = *i + 1;

		int result = -1;

		if (format[curr_i] != '.')
			return (result);
		result = 0;
		for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
		{
			if (is_digit(format[curr_i]))
			{
				result *= 10;
				result += format[curr_i] - '0';
			}
			else if (format[curr_i] == '*')
			{
				curr_i++;
				result = va_arg(list, int);
				break;
			}
			else
				break;
		}
		*i = curr_i - 1;
		return (result);
}
