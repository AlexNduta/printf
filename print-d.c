#include "main.h"

/**
 *int2string - changes number to a string
 *@num: number to be altered
 *
 *Return: character pointer
 */

char *int2string(int num)
{
	int length = 0;
	int i = 0;
	int div = 1;
	char *string;
	int temp = num;

	if (num == 0)
		length++;

	while (temp != 0)
	{
		length++;
		if (length > 1)
			div = div * 10;
		temp = temp / 10;
	}

	string = malloc(sizeof(char) * length + 2);
	if (string == NULL)
		return (NULL);

	if (num < 0)
	{
		string[0] = '-';
		i++;
	}

	while (div >= 1)
	{
		string[i++] = ((num / div) + '0');
		num = num % div;
		div = div / 10;
	}

	string[i] = '\0';
return (string);
}

/**
 *spec_d - specifier d handler function
 *@mylist: d/i argument passed to custom printf
 *
 *Return: character pointer
 */

char *spec_d(va_list mylist)
{
	int num = va_arg(mylist, int);

	return (int2string(num));
}
