#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

struct FormatSpecifier {
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

typedef struct FormatSpecifier FormatSpecifier;

int custom_printf(const char *format, ...);
int handle_print(const char *fmt, int *index, va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions for characters and strings */
int print_character(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions for numbers */
int print_integer(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list args, char buffer[], int flags, int width, int precision, int size);

int print_hexadecimal_custom(va_list args, char mapping[], char buffer[], int flags, char flag_char, int width, int precision, int size);

/* Function for printing non-printable characters */
int print_non_printable_chars(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Function for printing memory addresses */
int print_memory_address(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Functions for other specifiers */
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list list);
int get_precision(const char *format, int *index, va_list list);
int get_size(const char *format, int *index);

/* Function for printing a string in reverse */
int print_reversed_string(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Function for printing a string in ROT13 */
int print_rot13_string(va_list args, char buffer[], int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char character, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);
int write_integer(int index, char buffer[], int flags, int width, int precision, int length, char padding, char extra_char);
int write_memory_address(char buffer[], int index, int length, int width, int flags, char padding, char extra_char, int padding_start);
int write_unsigned(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);

/****************** UTILITIES ******************/

int is_printable_char(char c);
int append_hexadecimal_code(char character, char buffer[], int index);
int is_digit_char(char c);
long int convert_sized_number(long int number, int size);
long int convert_sized_unsigned(unsigned long int number, int size);

#endif /* MAIN_H */
