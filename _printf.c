#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

int handle_print(const char *format, int *i, va_list list, char buffer[],
                int flags, int width, int precision, int size)
{
    // Implementation of handle_print goes here
    // ...
}

int parse_format(const char *format, va_list list, char buffer[])
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            i++;
            printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
                return -1;
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    return printed_chars;
}

int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    va_list list;
    va_start(list, format);

    char buffer[BUFF_SIZE];
    int printed_chars = parse_format(format, list, buffer);

    va_end(list);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}
