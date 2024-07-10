#ifndef SVGLIB_H
#define SVGLIB_H

#include <iostream>
#include <string>
#include <cstdarg>

using unit_t = double;

void pformat(char* format,...);

namespace svg {
    void begin(unit_t width, unit_t height);
    void end();
    void text(unit_t x, unit_t y, std::string text, std::string colour, std::string stroke);
    void rect(unit_t x, unit_t y, unit_t width, unit_t height, std::string fill, std::string stroke);
}

#endif
