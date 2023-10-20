int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;

va_start(args, format);

while (format && *format)
{
if (*format != '%')
{
putchar(*format);
printed_chars++;
}
else if (*format == '%' && *(format + 1) == '%')
{
putchar('%');
printed_chars++;
format++;
}
else if (*format == '%' && *(format + 1) == 'c')
{
char c = va_arg(args, int);
putchar(c);
printed_chars++;
format++;
}
else if (*format == '%' && *(format + 1) == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
putchar(*str);
printed_chars++;
str++;
}
format++;
}
format++;
}

va_end(args);
return printed_chars;
}

