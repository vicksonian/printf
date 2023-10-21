#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Print a character.
 * @args: Argument list containing the character to print.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (putchar(c));
}

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
 * handle_specifier - Dispatch the
 * appropriate function for the given specifier.
 * @specifier: The format specifier.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int handle_specifier(const char *specifier, va_list args)
{
switch (*specifier)
{
case 'c':
return (print_char(args));
default:
putchar('%');
putchar(*specifier);
return (2);
}
}


