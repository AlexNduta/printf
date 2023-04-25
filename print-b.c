#include "main.h"
/**
 * int_to_binary - change int to binary
 * @list: unsigned int to change
 * Return: string in binary representation
 */
char *int_to_binary(va_list list)
{
	int index = 0;
	int power_of_two = 1;
	int temp_number;
	int number = va_arg(list, int);
	char *binary_string;

	binary_string = malloc(sizeof(char) * 33);
	if (binary_string == NULL)
		return (NULL);

	if (number < 0)
	{
		binary_string[index++] = '1';
		number = number * -1;
	}

	for (temp_number = number ; temp_number > 1 ; temp_number /= 2)
		power_of_two = power_of_two * 2;

	while (power_of_two > 0)
	{
		binary_string[index++] = (number / power_of_two + '0');
		number = number % power_of_two;
		power_of_two /= 2;
	}
	binary_string[index] = '\0';

	return (binary_string);
}
