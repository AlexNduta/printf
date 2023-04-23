#include "main.h"

/**
 *spec_s - string format specifier
 *@mylist: string argument passed to our custom printf
 *
 *Return: character pointer
 */
char *spec_s(va_list mylist)
{
	size_t i;
	char *str = va_arg(mylist, char *);
	size_t length = _strlen(str);
	char *s = malloc(length + 1);

	if (s == NULL)
		return (NULL);
	/*for loop to copy characters from the provided string to our new variabe s*/
	for (i = 0 ; i < length ; i++)
		s[i] = str[i];
	s[length] = '\0';
	return (s);
}
