#include "main.h"
#include <stdarg.h>

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - Printf function
* @format: string.
* Return: number of characters.
*/
int _printf(const char *format, ...)
{
		int i, printed = 0, num_char = 0;

		int flags, width, precision, size, buff_ind = 0;

		va_list list;

		char buffer[SIZE_OF_BUFF];

		if (format == NULL)
			return (-1);
		va_start(list, format);
		for (i = 0; format && format[i] != '\0'; i++)
		{
			if (format[i] != '%')
			{
				buffer[buff_ind++] = format[i];
				if (buff_ind == SIZE_OF_BUFF)
					print_buffer(buffer, &buff_ind);

				num_char++;
			}
			else
			{
				print_buffer(buffer, &buff_ind);
				flags = get_flags(format, &i);
				width = get_width(format, &i, list);
				precision = get_precision(format, &i, list);
				size = get_size(format, &i);
				++i;
				printed = handle_print(format, &i);
				if (printed == -1)
					return (-1);
				num_char += printed;
			}
		}
		print_buffer(buffer, &buff_ind);
		va_end(list);
		return (num_char);
}

/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @index: Index at which to add next char, represents the length.
*/

void print_buffer(char buffer[], int *index)
{
		if (*index > 0)
			write(1, &buffer[0], *index);
		*index = 0;
}
