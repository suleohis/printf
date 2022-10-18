#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed number of chars.
 */
int _printf(const char *format, ...)
{
	int i, printed_index = 0, num_of_printed_chars = 0;
	int flags, wid, prec, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			wid = get_width(format, &i, list);
			prec = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed_index = handle_print(format, &i, list, buffer,
				flags, wid, prec, size);
			if (printed_index == -1)
				return (-1);
			num_of_printed_chars += printed_index;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (num_of_printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if
 * @buffer: char array
 * @buff_ind: index.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
