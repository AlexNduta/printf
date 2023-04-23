#include "main.h"

/**
 *print-c - handle the c specifier in the format string
 *@mylist: the second arguments of our custom printf
 *
 *Return: character pointer or string array
 */
char *print_c(va_list mylist)
{
	char *s = malloc(sizeof(char) * 2);

	if (s == NULL)
		return (NULL);

	s[0] = va_arg(mylist, int);
	s[1] = '\0';

	return (s);
}
