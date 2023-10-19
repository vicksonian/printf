#include "main.h"

/**
 * get_function - function specifiers.
 *
 * @con_spec: Conversion specifiers.
 * @args: arguments.
 *
 * Return: char count.
 */

int functions(char con_spec, va_list args)
{
	int i = 0;
	int count_fun = 0;

	specifiers_t spec[] = {
		{'c', printChar},
		{'s', printString},
		{'%', printMod},
		{'d', printDigit},
		{'i', printDigit},
		{'r', printRevString},
		{0, NULL}
	};

	while (spec[i].specifiers)
	{
		if (con_spec == spec[i].specifiers)
			count_fun += spec[i].f(args);
		i++;
	}

	if (count_fun == 0)
	{
		count_fun += _putchar('%');
		count_fun += _putchar(con_spec);
	}

	return (count_fun);
}
