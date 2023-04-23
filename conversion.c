#include "main.h"
/**
 *handle_conversion - handles anything after % that can convert
 *@our_buffer: temp storage
 *@format: string to loop through
 *@i:loop counter
 *@length:loctaion in memory
 *@total:total size of length
 *@va_list: list of variadic arguments
 *Return: total
 */
int handle_conversion_specifier(char *our_buffer, const char *format,
int i, int length, int total, va_list mylist)
{
	char *(*holder)(va_list);
	char *string;
	int j = 0;

	holder = give_function(format[i]);
	if (holder == NULL)
	{
		length = check_buff(our_buffer, length);
		our_buffer[length++] = '%';
		total++;
		our_buffer[length++] = format[i];
		total++;
	} else
	{
		string = holder(mylist);
		if (string == NULL)
		{
			va_end(mylist);
			free(our_buffer);
			return (1);
		}
		if (format[i] == 'c' && string[0] == '\0')
		{
			length = check_buff(our_buffer, length);
			our_buffer[length++] = '\0';
			total++;
		}
		while (string[j] != '\0')
		{
			length = check_buff(our_buffer, length);
			our_buffer[length++] = string[j];
			total++;
			j++;
		}
		free(string);
	}
	return (total);
}
