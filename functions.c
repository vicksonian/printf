#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - Print an integer.
 * @args: The argument list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
return (printf("%d", num));
}

/**
 * print_string - Print a string.
 * @args: The argument list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
return (printf("%s", str));
}

/**
 * print_char - Print a character.
 * @args: The argument list containing the character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return (putchar(c));
}

/**
 * print_hex - Print a hexadecimal number.
 * @args: The argument list containing the hexadecimal number to print.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (printf("%x", num));
}

/**
 * handle_specifier - Dispatch the
 * appropriate function for the given specifier.
 * @specifier: The format specifier to handle.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
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
case 'x':
return (print_hex(args));
case 'u':
return (print("%u", num));
case 'f':
return (print_float(args));
case 'o':
return (printf("%o", va_arg(args, unsigned int)));
case 'p':
return (printf("%p", va_arg(args, void *)));
case 'e':
return (printf("%e", va_arg(args, double)));
default:
putchar('%');
putchar(*specifier);
return (2);
}
}

