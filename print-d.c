#include "main.h"

/**
 *int2string - changes number to a string
 *@num: number to be altered
 *
 *Return: character pointer


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

	string = malloc(sizeof(char) * (length + 2));
	if (string == NULL)
		return (NULL);

	if (num < 0)
	{
		string[0] = '-';
		num = -num;
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


 *spec_d - specifier d handler function
 *@mylist: d/i argument passed to custom printf
 *
 *Return: character pointer


char *spec_d(va_list mylist)
{
	int num = va_arg(mylist, int);

	return (int2string(num));
}

int int2string(char *buffer, int value) {
    int length = 0, j, i;
    int is_negative = 0;

    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    do {
        buffer[length++] = (char)(value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (is_negative) {
        buffer[length++] = '-';
    }

    buffer[length] = '\0';

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    return length;
}


char *spec_d(va_list args) {
    int arg = va_arg(args, int);
    char *str = (char *)malloc(12);
    if (str == NULL) {
        return NULL;
    }
    int2string(str, arg);
    return str;
} */



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
         {                 string[0] = '-';
         num = -num;
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


 char *spec_d(va_list mylist)
 {
         int num = va_arg(mylist, int);

         return (int2string(num));
 }
