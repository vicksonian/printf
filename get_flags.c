#include "main.h"

/**
* init_flags - Initialize flag variables to their default values
* @flags: A pointer to the Flags structure to be initialized
*/
void init_flags(Flags *flags)
{
flags->minus = 0;
flags->plus = 0;
flags->zero = 0;
flags->hash = 0;
flags->space = 0;
flags->width = 0;
flags->precision = -1;
flags->percent = 0;
}

/**
*parse_flags - Parse and set the flags based on the format specifier
*@format: The format string to be parsed
*@flags: A pointer to the Flags structure where the parsed flags will be stored
*@i: A pointer to the current index in the format string
*/
void parse_flags(const char *format, Flags *flags, int *i)
{
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '%', '\0'};
const int FLAGS_ARR[] = {1, 2, 4, 8, 16, 32, 0};

int curr_i = *i;
int j;
int parsed_flags = 0;

while (format[curr_i] != '\0')
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
{
if (format[curr_i] == FLAGS_CH[j])
{
parsed_flags |= FLAGS_ARR[j];
break;
}
}

if (FLAGS_CH[j] == 0)
break;

curr_i++;
}

*i = curr_i - 1;

	/*Merge the parsed flags with the existing flags*/
flags->flags |= parsed_flags;
}

/**
* main - Sample usage of flag parsing
* Return: Always 0
*/
int main(void)
{
Flags flags;
init_flags(&flags);
const char *format = "%-+05.2f";
int i = 0;
parse_flags(format, &flags, &i);

printf("Parsed flags: minus=%d, plus=%d, zero=%d, hash=%d, space=%d,
percent=%d, width=%d, precision=%d\n",
flags.minus, flags.plus, flags.zero, flags.hash, flags.space, flags.percent,
flags.width, flags.precision);

	return (0);
}
