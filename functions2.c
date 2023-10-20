#include "main.h"
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

