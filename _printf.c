#include "main.h"
/**
 * _printf - printf function
 * @format: const char pointer
 * Return: b_len
 */

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int char_count = 0;
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
break;
}
if (*format == 'd')
{
int num = va_arg(args, int);
char_count += printf("%d", num);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
char_count += printf("%s", str);
}
else
{
putchar(*format);
char_count++;
}
}
else
{
putchar(*format);
char_count++;
}
format++;
}

va_end(args);
return (char_count);
}

/**
 * main - Entry point
 *
 * This is the main function of the program. It tests the _printf function.
 *
 * Return: 0 (success)
 */
int main(void)
{
int num = 42;
char *str = "Hello, World!";

int count = _printf("This is a number: %d\nThis is a string: %s\n", num, str);
printf("Total characters printed: %d\n", count);

return (0);
}
