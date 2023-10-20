#include "main.h"

/**
 * init_size - Initialize size to its default value.
 * @size: A pointer to the Size struct to be initialized.
 *
 * This function initializes the size modifier to NONE.
 */
void init_size(Size *size)
{
size->modifier = NONE;
}

/**
 * parse_size - Parse and set the size modifier based on the format specifier.
 * @format: The format specifier to parse.
 * @size: A pointer to the Size struct to store the parsed size modifier.
 *
 * This function parses the format specifier to determine the size modifier.
 * It supports 'h', 'hh', 'l', 'll', 'j', 'z', and other size modifiers.
 */
void parse_size(const char *format, Size *size)
{
size->modifier = NONE;

if (*format == 'h')
{
size->modifier = SHORT;
format++;
if (*format == 'h')
{
size->modifier = CHAR;
format++;
}
}
else if (*format == 'l')
{
size->modifier = LONG;
format++;
if (*format == 'l')
{
size->modifier = LONG_LONG;
format++;
}
}
else if (*format == 'j')
{
size->modifier = INTMAX_T;
format++;
}
else if (*format == 'z')
{
size->modifier = SIZE_T;
format++;
}

}

/**
 * is_size_specified - Check if a size modifier is specified.
 * @size: The Size struct to check.
 *
 * Return: 1 if a size modifier is specified, 0 otherwise.
 */
int is_size_specified(Size size)
{
return (size.modifier != NONE);
}

/**
 * get_size_modifier - Get the specified size modifier.
 * @size: The Size struct containing the size modifier.
 *
 * Return: The size modifier as a SizeModifier enum value.
 */
SizeModifier get_size_modifier(Size size)
{
return (size.modifier);
}

