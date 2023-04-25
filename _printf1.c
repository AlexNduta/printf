#include  "main.h"
int _printf(const char *format, ...) {
    int length = 0, i;
    char buffer[1024] = {0};
    va_list args;
    va_start(args, format);

    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
            format_func func = give_function(format[i + 1]);
            if (func != NULL) {
                char *str = func(args);
                if (str != NULL) {
                    int str_len =_strlen(str);
                    length = check_buff(buffer, length + str_len);
                    strcat(buffer, str);
                    length += str_len;
                    free(str);
                } else {
                    return -1; /* Return error code on memory allocation failure */
                }
                i++; /* Skip the next character after the format specifier */
            } else {
                /* Unsupported format specifier, simply copy to buffer */
                length = check_buff(buffer, length + 1);
                buffer[length++] = format[i];
            }
        } else {
            /* Copy non-format specifier character to buffer */
            length = check_buff(buffer, length + 1);
            buffer[length++] = format[i];
        }
    }

    va_end(args);

    /* Flush the buffer */
    write_to_buffer(buffer, length);

    return length;
}
