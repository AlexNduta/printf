#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *spec_c(va_list mylist);
char *spec_s(va_list mylist);
char *spec_d(va_list mylist);
int _strlen(char *s);
int _printf(const char *format, ...);

/* Helper functions */
int check_buff(char *our_buffer, int length);
char *create_buff(void);
void write_to_buffer(char *our_buffer, int length, va_list mylist);
int handle_conversion_specifier(char *our_buffer, const char *format, int i, int length, int total, va_list mylist);
int handle_percent(char *our_buffer, const char *format, int i, int length, int total, va_list mylist);

#endif
