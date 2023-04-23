#include "main.h"

/**
 *_printf - prints to the stdout
 *@format: mandatory input string
 *Return: the count
 */
int _printf(const char *format, ...)
{
	int i = 0, length = 0, total = 0;
	va_list mylist;
	char *our_buffer, *string, *(*holder)(va_list);

	if (format == NULL)
		return (1);

	our_buffer = create_buff();

	if (our_buffer == NULL)
		return (1);

	va_start(mylist, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] != '%') /*write to temp buffer till we get "%" */
		{
			length = check_buff(our_buffer, length);
			our_buffer[len++] = format[i++];
			total++;
		} else /*incase we get '%' */
		{
			i++;
			if (format[i] == '\0') /* incase we have single % at the end */
			{
/* incase we have a single % at the end, we end the function */
				total = handle_percent(our_buffer, format, i, length, total, mylist);
			} else
			{
				total = handle_conversion_specifier(our_buffer, format, i, total, mylist);
			}
		}
	}
	write_buff(our_buffer, length, mylist);
	return (total);
}

