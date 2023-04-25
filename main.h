#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
/*main functions */
char *spec_c(va_list mylist);
char *spec_s(va_list mylist);
char *spec_d(va_list mylist);
int _strlen(char *s);
typedef char *(*format_func)(va_list);
/*char* (*give_function(char i))(va_list); */
format_func give_function(char c);
/* int _printf(const char *format, ...); */
int _printf(const char *format, ...);
/* Helper functions */
int check_buff(char *our_buffer, int length);
char *create_buff(void);
void write_to_buffer(char *our_buffer, int length);
/*void write_to_buffer(char *our_buffer, int length, va_list mylist)*/
#endif
