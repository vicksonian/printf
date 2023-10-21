#include "main.h"
#include <stdarg.h>

/**
 * print_octal - Print an octal number.
 * @args: Argument list containing the octal number to print.
 *
 * Return: Number of characters printed.
 */
int print_octal(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (printf("%o", num));
}

/**
 * print_binary - Print a binary number.
 * @args: Argument list containing the binary number to print.
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (printf("%b", num));
}

/**
 * handle_specifier - Dispatch
 * the appropriate function for the given specifier.
 * @specifier: The format specifier.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int handle_specifier(const char *specifier, va_list args)
{
switch (*specifier)
{
case 'd':
return (print_int(args));
case 's':
return (print_string(args));
case 'c':
return (print_char(args));
case 'u':
return (print_unsigned int(args));
default:
putchar('%');
putchar(*specifier);
return (2);
}
}

