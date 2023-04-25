#include "main.h"
#include <stdarg.h>

/**
* _printf - Printf function
* @format: string.
* Return: number of characters.
*/
int _printf(const char *format, ...)
{
		int i, printed = 0, num_char = 0;

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
				printed = handle_print(format, &i);
				if (printed == -1)
					return (-1);
				num_char += printed;
			}
		}
		va_end(list);
		return (num_char);
}
