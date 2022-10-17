#ifndef _PRINTF_
#define _PRINTF_

#include <stdio.h>
#include <limits.h>

/**
 * struct convert - defines a structure for symbols and functions
 * @sym: The operator
 * @f: function
 */

typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} conver_t;

int _printf(const char *format, ...);
int par(const char *format, conver_t f_list[], va_list arg_list);

#endif
