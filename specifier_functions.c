#include "main.h"

/**
 *give_function - allocates a speficier function
 *@i: character to be searcehd for in the array
 *
 *Return: return a character pointer
 */
char* (*give_function(char i))(va_list)
{
	int k = 0;
	char ids[] = {'c', 's', 'd', 'i'};

	while (ids[k] != '0')
	{
		if (ids[k] == i)
			break;
		k++;
	}
	switch (ids[k])
	{
		case 'c':
			return (spec_c);
		case 's':
			return (spec_s);
		case 'd':
		case 'i':
			return (spec_d);
		default:
			return (NULL);
	}
}
