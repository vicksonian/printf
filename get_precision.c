#include "main.h"

/**
 * init_precision - Initialize precision to its default value.
 * @precision: A pointer to the Precision struct to be initialized.
 *
 * This function sets the specified flag to 0 and the value to 0.
 */
void init_precision(Precision *precision)
{
precision->specified = 0;
precision->value = 0;
}

/**
 * parse_precision - Parse and set the precision based on the format specifier.
 * @format: The format specifier to parse.
 * @precision: A pointer to the Precision struct to store the parsed precision.
 *
 * This function parses the format specifier
 * to determine the precision, if specified.
 */
void parse_precision(const char *format, Precision *precision)
{
precision->specified = 0;
precision->value = 0;

if (*format == '.')
{
format++;
precision->specified = 1;
while (*format >= '0' && *format <= '9')
{
precision->value = precision->value * 10 + (*format - '0');
format++;
}
}
}

/**
 * is_precision_specified - Check if precision is specified.
 * @precision: The Precision struct to check.
 *
 * Return: 1 if precision is specified, 0 otherwise.
 */
int is_precision_specified(Precision precision)
{
return (precision.specified);
}

/**
 * get_precision_value - Get the value of the specified precision.
 * @precision: The Precision struct containing the precision value.
 *
 * Return: The value of the specified precision.
 */
int get_precision_value(Precision precision)
{
return (precision.value);
}

