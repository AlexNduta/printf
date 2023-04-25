#include "main.h"

/**
 *give_function - allocates a speficier function
 *@i: character to be searcehd for in the array
 *
 *Return: return a character pointer
 *
 */
format_func give_function(char c) {
    /* Add cases for other format specifiers as needed */
    switch (c) {
        case 'c':
            return spec_c;
        case 's':
            return spec_s;
        case 'd':
            return spec_d;
        default:
            return (NULL);
    }
}
