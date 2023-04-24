#include "main.h"
#include <stdarg.h>

/**
* _printf - Printf function
* @format: string.
* Return: number of characters.
*/
int _printf(const char *format, ...)
{
		int i, num_char = 0;

		va_list list;

		if (format == NULL)
			return (-1);
		va_start(list, format);
		for (i = 0; format && format[i] != '\0'; i++)
		{
			if (format[i] != '%')
			{
				num_char++;
			}
			else
			{
				++i;
				if (format[i + 1] == '\0')
				{
				}
				else if (format[i] != 'c' && format[i] != 's' && format[i] != '\0')
				{
					num_char = num_char + 2;
				}
			}
		}
		va_end(list);
		return (num_char);
}
