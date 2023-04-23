#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int check_buff(char *our_buffer, int length);
char *create_buff(void);
void write_to_buffer(char *our_buffer, int length, va_list mylist);
#endif
