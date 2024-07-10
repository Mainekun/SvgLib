#include "svg.hpp"
#include <cstdarg>

void pformat(char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            std::cout << va_arg(args, char*);
        }
        else {
            std::cout << *format;
        }
        format++;
    }

    va_end(args);
}

void svg::begin(unit_t width, unit_t height) {

}
