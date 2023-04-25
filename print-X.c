#include "main.h"
/**
 * unsigned_int_to_hex_upper - change unsigned int to hexadecimal
 * @list: unsigned int to change
 * Return: string with hexadecimal representation of unsigned int
 */
char *unsigned_int_to_hex_upper(va_list list)
{
	unsigned int number = va_arg(list, unsigned int);
	char *hex_string;
	int length = 0;
	unsigned int temp_number = number;

	do {
		length++;
		temp_number = temp_number / 16;
	} while (temp_number);

	hex_string = malloc(sizeof(char) * (length + 1));
	if (hex_string == NULL)
		return (NULL);

	hex_string[length] = '\0';

	while (length--)
	{
		hex_string[length] = "0123456789ABCDEF"[number % 16];
		number = number / 16;
	}
	return (hex_string);
}
