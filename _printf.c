#include "main.h"
#include <stdio.h>

/**
* print_char - Prints a character to standard output.
* @args: The argument list containing the character to print.
*
* Return: The number of characters printed (always 1).
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
write(1, &c, 1);
return (1);
}

/**
* print_string - Prints a string to standard output.
* @args: The argument list containing the string to print.
*
* Return: The number of characters printed (excluding the null byte).
*/
int print_string(va_list args)
{
char *str = va_arg(args, char *);

if (str)
{
int char_count = 0;

while (*str)
{
write(1, str, 1);
str++;
char_count++;
}
return (char_count);
}
return (0);
}

/**
* print_integer - Prints an integer to standard output.
* @args: The argument list containing the integer to print.
*
* Return: The number of characters printed.
*/
int print_integer(va_list args)
{
int num = va_arg(args, int);
char num_str[12];
int num_len = snprintf(num_str, sizeof(num_str), "%d", num);

write(1, num_str, num_len);
return (num_len);
}

/**
* _printf - Produces output according to a format.
* @format: Is a character string. The format string
* is composed of zero or more directives.
*
* Return: The number of characters printed (excluding
* the null byte used to end output to strings).
*/
int _printf(const char *format, ...)
{
va_list args;
int char_count = 0;

if (format == NULL)
return (-1);

va_start(args, format);

while (*format)
{
}

va_end(args);
return (char_count);
}
