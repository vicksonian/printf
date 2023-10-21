#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h> // Include stdio.h for sprintf
#include <stdbool.h> // Include stdbool.h for boolean support

/* utils.c */
int _strlen(const char *);
int print(char *);
char *itoa(long int, int);
char *dtoa(double, int); // Added for floating-point numbers
char *itoh(unsigned int, bool); // Added for hexadecimal numbers

/* printf.c */
int _printf(const char *, ...);

/* handler.c */
int handler(const char *, va_list);
int percent_handler(const char *, va_list, int *);

/* printers */
int print_char(va_list);
int print_string(va_list);
int print_float(va_list);
int print_unsigned(va_list);
int print_hex(va_list);

/** * struct _format - Typedef struct * * @type: Format * @f: The function associated **/
typedef struct _format {
    char type;
    int (*f)(va_list);
} format;

#endif

