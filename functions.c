#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - Print an integer.
 * @args: Argument list containing the integer to print.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
return (printf("%d", num));
}

/**
 * print_string - Print a string.
 * @args: Argument list containing the string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
return (printf("%s", str));
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
default:
putchar('%');
putchar(*specifier);
return (2);
}
}

