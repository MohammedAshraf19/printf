#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @index: ind.
 * Return: integer;
 */

int handle_print(const char *fmt, int *index )
{
        int i, unknow_len = 0, printed_chars = -1;

        fmt_t print_type[] = {
                {'c', print_char}, {'s', print_string}, {'%', print_percent},{'\0', NULL}
        };


        for (i = 0; print_type[i].fmt != '\0'; i++)

                if (fmt[*index] == print_type[i].fmt)
                    return (0);


        if (print_type[i].fmt == '\0')

        {

                if (fmt[*index] == '\0')

                        return (-1);

                unknow_len += write(1, "%%", 1);

                if (fmt[*index - 1] == ' ')

                        unknow_len += write(1, " ", 1);


                unknow_len += write(1, &fmt[*index], 1);

                return (unknow_len);

        }

        return (printed_chars);

}
