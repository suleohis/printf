#include "main.h"


int par(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, val, chars;

	chars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{

			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					val = f_list[j].f(arg_list);
					if (val == -1)
						return (-1);
					chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format([i + 1]));
					chars = chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			chars++;
		}
	}
	return (chars);
}
