#include <stdio.h>
#include <stdarg.h>

void color_print_green(const char *format, ...)
{
    // ANSI escape code for green text
    const char *green_color = "\x1b[32m";
    // ANSI escape code to reset text color
    const char *reset_color = "\x1b[0m";

    // Print the green color escape code
    printf("%s", green_color);

    // Initialize variable argument list
    va_list args;
    va_start(args, format);

    // Print the formatted text
    vprintf(format, args);

    // End variable argument list
    va_end(args);

    // Print the reset color escape code
    printf("%s", reset_color);
}