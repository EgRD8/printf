#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        write(1, &c, 1);
                        printed_chars++;
                        break;
                    }
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        int len = 0;

                        while (str[len])
                            len++;

                        write(1, str, len);
                        printed_chars += len;
                        break;
                    }
                case '%':
                    {
                        write(1, "%", 1);
                        printed_chars++;
                        break;
                    }
                default:
                    {
                        write(1, "%", 1);
                        write(1, &(*format), 1);
                        printed_chars += 2;
                        break;
                    }
            }
        }
        else
        {
            write(1, &(*format), 1);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}
