#include "main.h"

/**
 *_printf - prints to the stdout
 *@format: mandatory input string
 *Return: the count
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list mylist;

	va_start(mylist, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(mylist, int);

				putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(mylist, char *);

				while (*str)
				{
				putchar(*str);
				str++;
				count++;
				}
			}
		} else
		{
			putchar(format[i]);
			count++;
		}
	i++;
	}
	va_end(mylist);
	return (count);
}
