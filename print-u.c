#include "main.h"
/**
 * unsigned_int_to_string - change unsigned int to string
 * @list: unsigned int to change
 * Return: string representation of unsigned int
 */
char *unsigned_int_to_string(va_list list)
{
	unsigned int number = va_arg(list, unsigned int);
	char *string;
	int length = 0;
	unsigned int temp_number = number;

	do {
		length++;
		temp_number = temp_number / 10;
	} while (temp_number);

	string = malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);

	string[length] = '\0';

	while (length--)
	{
		string[length] = (number % 10) + '0';
		number = number / 10;
	}

	return (string);
}
