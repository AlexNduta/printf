#include "main.h"

/**
 * unsigned_int_to_octal - change unsigned int to octal
 * @list: unsigned int to change
 * Return: string with octal representation of unsigned int
 */
char *unsigned_int_to_octal(va_list list)
{
	unsigned int number = va_arg(list, unsigned int);
	char *octal_string;
	int length = 0;
	unsigned int temp_number = number;

	do {
		length++;
		temp_number = temp_number / 8;
	} while (temp_number);

	octal_string = malloc(sizeof(char) * (length + 1));
	if (octal_string == NULL)
		return (NULL);

	octal_string[length] = '\0';

	while (length--)
	{
		octal_string[length] = (number % 8) + '0';
		number = number / 8;
	}

	return (octal_string);
}
