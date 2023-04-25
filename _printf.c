#include "main.h"

/**
 *_printf - prints to the stdout
 *@format: mandatory input string
 *Return: the count *
int _printf(const char *format, ...)
{
	int i = 0, j = 0, length = 0, total = 0;
	va_list mylist;
	char *our_buffer, *string;
	char *(*holder)(va_list);

	if (format == NULL)
		return (1);

	our_buffer = create_buff();

	if (our_buffer == NULL)
		return (1);

	va_start(mylist, format);

	while (*format)
	{
		if (format[i] != '%')
		{
			length = check_buff(our_buffer, length);
			our_buffer[length++] = format[i++];
			total++;
		} else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(mylist);
				free(our_buffer);
				return (1);
			}
			if (format[i] == '%')
			{
				length = check_buff(our_buffer, length);
				our_buffer[length++] = format[i];
				total++;
			} else
			{
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
					while (string[j] == '\0')
					{
						length = check_buff(our_buffer, length);
						our_buffer[length++] = string[j];
						total++;
					}
					free(string);
				}
			} i++;
		}
	}
	write_to_buffer(our_buffer, length, mylist);
	return (total);
} */
