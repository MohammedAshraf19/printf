#include "main.h"

/**
* print_unsigned - Prints an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		int i = SIZE_OF_BUFF - 2;

		unsigned long int num = va_arg(types, unsigned long int);

		num = convert_size_unsgnd(num, size);
		if (num == 0)
			buffer[i--] = '0';
		buffer[SIZE_OF_BUFF - 1] = '\0';
		while (num > 0)
		{
			buffer[i--] = (num % 10) + '0';
			num /= 10;
		}
		i++;
		return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_octal - Prints an unsigned number in octal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		int i = SIZE_OF_BUFF - 2;

		unsigned long int num = va_arg(types, unsigned long int), init_num = num;

		UNUSED(width);
		num = convert_size_unsgnd(num, size);
		if (num == 0)
			buffer[i--] = '0';
		buffer[SIZE_OF_BUFF - 1] = '\0';
		while (num > 0)
		{
			buffer[i--] = (num % 8) + '0';
			num /= 8;
		}
		if (flags & FLAG_HASH && init_num != 0)
			buffer[i--] = '0';
		i++;
		return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		return (print_hexa(types, "0123456789abcdef", buffer,
					flags, 'x', width, precision, size));
}

/**
* print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
* @types: Arguments
* @buffer: Buffer array to handle print
* @flags:  integer.
* @width: Integer.
* @precision: Precision specification
* @size: Size specifier
* Return: integer.
*/


int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
		return (print_hexa(types, "0123456789ABCDEF", buffer,
					flags, 'X', width, precision, size));
}

/**
* print_hexa - Prints a hexadecimal number in lower or upper
* @types: Arguments
* @buffer: Buffer array to handle print
* @flags:  integer.
* @width: Integer.
* @precision: Precision specification
* @size: Size specifier
* @map_to: Array of values to map the number to
* @flag_ch: Calculates active flags
* @size: Size specification
* Return: integer.
*/

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)

{
		int i = SIZE_OF_BUFF - 2;

		unsigned long int num = va_arg(types, unsigned long int);

		unsigned long int init_num = num;

		UNUSED(width);
		num = convert_size_unsgnd(num, size);
		if (num == 0)
			buffer[i--] = '0';
		buffer[SIZE_OF_BUFF - 1] = '\0';
		while (num > 0)
		{
			buffer[i--] = map_to[num % 16];
			num /= 16;
		}
		if (flags & FLAG_HASH && init_num != 0)
		{
			buffer[i--] = flag_ch;
			buffer[i--] = '0';
		}
		i++;
		return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
