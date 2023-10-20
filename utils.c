#include "main.h"

/**
* ascii_to_hex - Convert an ASCII character to its hexadecimal representation.
* @c: The ASCII character to be converted.
*
* Return: The hexadecimal representation as a string.
*/
char *ascii_to_hex(char c)
{
static char hex[3];
snprintf(hex, sizeof(hex), "%02X", (unsigned char)c);
return (hex);
}

/**
* cast_to_size - Cast a numeric value to the specified size.
* @num: The number to be casted.
* @size: The size indicating the type to be casted.
*
* Return: The casted value of num.
*/
long int cast_to_size(long int num, int size)
{
switch (size)
{
case S_LONG:
return (long int(num));
case S_SHORT:
return (short(num));
default:
return (int(num));
}
}

/**
* str_to_int - Convert a string to an integer.
* @str: The string to be converted.
*
* Return: The integer value, or 0 if the conversion fails.
*/
int str_to_int(const char *str)
{
if (str == NULL)
{
fprintf(stderr, "Error: NULL input\n");
return (0);
}

int result = 0;
int sign = 1;
int i = 0;

/*Handle leading '+' or '-' signs*/
if (str[i] == '-')
{
sign = -1;
i++;
}
else if (str[i] == '+')
{
i++;
}

/*Iterate through the string and build the integer*/
while (str[i] != '\0')
{
if (is_digit(str[i]))
{
result = result * 10 + (str[i] - '0');
i++;
}
else
{
fprintf(stderr, "Error: Non-digit character in input\n");
return (0);
}
}

return (sign *result);
}

/**
* is_printable - Evaluates if a char is printable.
* @c: Char to be evaluated.
*
* Return: 1 if c is printable, 0 otherwise.
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
else
return (0);
}

/**
* is_digit - Verifies if a character is a digit.
* @c: Char to be evaluated.
*
* Return: 1 if c is a digit, 0 otherwise.
*/
int is_digit(char c)
{
return (c >= '0' && c <= '9');
}
