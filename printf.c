#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a single character to stdout
 *
 * @args: a variable argument list containing a single int argument
 *
 * Return: the number of characters printed (1 if successful, -1 if not)
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - prints a null-terminated string to stdout
 *
 * @args: a variable argument list containing a single char * argument
 *
 * Return: the number of characters printed excluding null byte
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * _printf - prints formatted output to stdout
 *
 * @format: a string containing zero or more directives
 *          for how to print the arguments
 * @...: the variable arguments to print, based on the directives in @format
 *
 * Return: the number of characters printed (excludin the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				count += print_char(args);
			}
			else if (*format == 's')
			{
				count += print_string(args);
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

