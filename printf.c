#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - This function prints the,
 * argument passed to it to the stdout.
 * @format: The argument to be printed to the,
 * stdout.
 * @...: The variable arguments to be printed.
 *
 * Return: It returns the number of arguments,
 * printed.
 */
int _printf(const char *format, ...)
{
	va_list arg_ptr;
	char *str;
	char k;
	int args = 0, len = 0, len1 = 0, m = 0, p;

	va_start(arg_ptr, format);
	while (format[args] != '\0')
	{
		if (format[args] == '%')
		{
			switch (format[args + 1])
			{
				case 'c':
					p = va_arg(arg_ptr, int);
					len1 = len1 + write(1, &p, 1);
					len1--;
					break;
				case 's':
					str = va_arg(arg_ptr, char *);
					while (str[m] != '\0')
						m++;
					len1 = len1 + write(1, str, m);
					len1--;
					break;
				case '%':
					len1 = len1 + write(1, &p, 1);
					len--;
					break;
			}
		}
		else
		{
			k = format[args];
			len = len + write(1, &k, 1);
			len--;
		}
		args++;
	}
	va_end(arg_ptr);
	return (len + len1);
}
