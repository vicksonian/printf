#include "main.h"
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
 * print_unsigned - Print an unsigned integer.
 * @args: Argument list containing the unsigned integer to print.
 *
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (printf("%u", num));
}

/**
 * print_hex - Print a hexadecimal number.
 * @args: Argument list containing the hexadecimal number to print.
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (printf("%x", num));
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
default:
putchar('%');
putchar(*specifier);
return (2);
}
}

