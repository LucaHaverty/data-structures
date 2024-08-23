#include <stdio.h>
#include <stdarg.h>

void color_print_green(const char *format, ...)
{
    const char *green_color = "\e[1;32m";
    const char *reset_color = "\x1b[0m";
    printf("%s", green_color);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("%s", reset_color);
}

void color_print_red(const char *format, ...)
{
    const char *red_color = "\e[1;31m";
    const char *reset_color = "\x1b[0m";
    printf("%s", red_color);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("%s", reset_color);
}