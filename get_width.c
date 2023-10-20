#include "main.h"
#include <stdio.h>

/**
 * init_width - Initialize width to its default value.
 * @width: A pointer to the Width struct to be initialized.
 *
 * This function sets the specified flag to 0 and the value to 0.
 */
void init_width(Width *width)
{
width->specified = 0;
width->value = 0;
}

/**
 * parse_width - Parse and set the width based on the format specifier.
 * @format: The format specifier to parse.
 * @width: A pointer to the Width struct to store the parsed width.
 *
 * This function parses the
 * format specifier to determine the width, if specified.
 */
void parse_width(const char *format, Width *width)
{
width->specified = 0;
width->value = 0;

while (*format >= '0' && *format <= '9')
{
width->specified = 1;
width->value = width->value * 10 + (*format - '0');
format++;
}
}

/**
 * get_width_value - Get the value of the specified width.
 * @width: The Width struct containing the width value.
 *
 * Return: The value of the specified width.
 */
int get_width_value(Width width)
{
return (width.value);
}

/**
 * is_width_specified - Check if width is specified.
 * @width: The Width struct to check.
 *
 * Return: 1 if width is specified, 0 otherwise.
 */
int is_width_specified(Width width)
{
return (width.specified);
}

/**
 * main - Entry point for testing the printf implementation.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
int len;

len = _printf("Let's try to printf a simple sentence.\n");
printf("Length:[%d]\n", len);

len = _printf("Character:[%c]\n", 'H');
printf("Length:[%d]\n", len);

len = _printf("String:[%s]\n", "I am a string !");
printf("Length:[%d]\n", len);

len = _printf("Hexadecimal:[%x]\n", 255);
printf("Length:[%d]\n", len);

len = _printf("Unknown:[%r]\n");
printf("Length:[%d]\n", len);

return (0);
}

