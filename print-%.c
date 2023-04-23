#include "main.h"
/*
 *handle_percent - handles different occurence of %
 *@our_buffer: our temporary storage before printing
 *@format: our string passed to the printf
 *@i: variable counter
 *@length: the size of string at a given time
 *the total length of our string to be printed
 */
int handle_percent(char *our_buffer, const char *format, int i,
int length, int total, va_list mylist)
{
	i++; /* skip the current % charcter */
	if (format[i] == '\0')
	{
		va_end(mylist);
		free(our_buffer);
		return (-1);
	}

	if (format[i] == '%') /* check if it a double % */
	{
		length = check_buff(our_buffer, length);
		our_buffer[length++] = format[i];
		total++;
	} else
	{
		length = check_buff(our_buffer, length);
		our_buffer[length++] = '%';
		total++;
		our_buffer[length++] = format[i];
		total++;
	}
	return (total)
}
