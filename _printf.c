#include "main.h"

/**
 * _printf - Receive the string and other paramenter
 * @format: string containing all the desired character
 *
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;

	conver_t fun_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	
	i = par(format, f_list, arg_list);

	va_end(arg_list);

	return (i);
}
