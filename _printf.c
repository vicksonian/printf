#include "main.h"

/**
* _printf - Produces output according to a format
* @format: Is a character string. The format string
* is composed of zero or more directives
*
* Return: The number of characters printed (excluding
* the null byte used to end output to strings)
**/
int _printf(const char *format, ...)
{
va_list args;
int char_count = 0;

if (format == NULL)
return (-1);

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
break;

if (*format == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
char_count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str)
{
while (*str)
{
write(1, str, 1);
str++;
char_count++;
}
}
}
else if (*format == '%')
{
write(1, "%", 1);
char_count++;
}
}
else
{
write(1, format, 1);
char_count++;
}

format++;
}

va_end(args);
return (char_count);
}

