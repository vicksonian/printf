#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* Function prototypes */

int custom_printf(const char *format, ...);
void handle_string(const char *str);
void handle_char(char c);
void handle_integer(int num);
void handle_unsigned(unsigned int num);
void handle_octal(unsigned int num);
void handle_hexadecimal(unsigned int num, int is_upper);
void handle_pointer(void *ptr);
void handle_binary(unsigned int num);
void handle_percent(void);

/* functions1.c */
int _printf(const char *format, ...);

/* functions2.c */
int custom_putchar(char c);

/* get_flags.c */
int is_flag(char c);
int get_flags(const char *format, int *index);

/* get_width.c */
int get_width(const char *format, int *index);

/* get_precision.c */
int get_precision(const char *format, int *index);

/* get_size.c */
int get_size(const char *format, int *index);

/* _putchar.c */
int _putchar(char c);

/* handle_print.c */
int handle_print(const char *format, va_list args);

/* write_handlers.c */
int write_char(char c);
int write_string(const char *str);
int write_int(int num);
int write_unsigned(unsigned int num);
int write_hexadecimal(unsigned int num, int is_upper);
int write_octal(unsigned int num);
int write_binary(unsigned int num);

/* utils.c */
int num_length(int num);
char *reverse_string(char *str);
char *itoa(int num);
char *uitoa(unsigned int num);

#endif

