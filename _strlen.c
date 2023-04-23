#include "main.h"

/**
 *_strlen - counts the length of the string
 *@s: the string we are counting
 *
 *Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;
	/*count from start os string to the null byte*/
	while (*s != '\0')
	{
		length++;
		s++;
	}
return (length);
}
