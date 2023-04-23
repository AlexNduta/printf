#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *print_c(va_list mylist);
int _printf(const char *format, ...);
int check_buff(char *our_buffer, int length);
char *create_buff(void);
void write_to_buffer(char *our_buffer, int length, va_list mylist);
int handle_conversion_specifier(char *our_buffer, const char *format, int i, int length, int total, va_list mylist);
int handle_percent(char *our_buffer, const char *format, int i, int length, int total);

#endif
