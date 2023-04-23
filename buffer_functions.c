#include "main.h"
/**
 *check_buff - checks if the memory is the buffer size
 * is almost depleted then writes everything to stdou
 *and switch length back to 0
 *@buffer: this is the temporary storage holding content to print
 *@length: the current position in our buffer
 *
 *Return: the current position in our buffer
 */
int check_buff(char *our_buffer, int length)
{
	if (length > 1020)
	{
		write(1, our_buffer, length);
		length = 0;
	}
	return (length);
}


/**
 *create_buff - create a buffer of size 1024
 *that we use to temporarily store our strings before being printed
 *
 *Return: a pointer to our buffer
 */
char *create_buff(void)
{
	char *our_buffer;

	our_buffer = malloc(sizeof(char) * 1024);
	if (our_buffer == NULL)
		return (NULL);
	return (our_buffer);
}


/**
 *write_to_buffer - prints our_buffer then frees it then frees the va_list
 *@our_buffer: buffer holding values to be printed
 *@length: size of the content to be printed
 *@mylist: the list of variables to be printed
 */
void write_to_buffer(char *our_buffer, int length, va_list mylist)
{
	char *buff_to_print;

	buff_to_print = realloc(our_buffer, length);

	write(1, buff_to_print, length);

	free(buff_to_print);
	va_end(mylist);
}
