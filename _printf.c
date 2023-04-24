#include "main.h"

/**
 *_printf - prints to the stdout
 *@format: mandatory input string
 *Return: the count
 */
int _printf(const char *format, ...)
{
	int i = 0, length = 0, total = 0;
	va_list mylist, mylist_copy; /*add mylist_copy */
	char *our_buffer;

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
			our_buffer[length++] = format[i++];
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
				va_copy(mylist_copy, mylist); /* create a copy of va_list */
				total = handle_conversion_specifier(our_buffer, format, i,
				length, total, mylist_copy); /*pass the copy of va_list */
				va_end(mylist_copy); /* End the copy of va_list after its used */
			}
		}
	}
	write_to_buffer(our_buffer, length, mylist);
	return (total);
}

