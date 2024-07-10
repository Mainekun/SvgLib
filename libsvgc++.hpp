#ifndef SVGLIB_H
#define SVGLIB_H

#include <iostream>
#include <string>
#include <cstdarg>

void fcout(std::string format...);
void fcerr(std::string format...);


using unit_t = double;
namespace svg {
    void begin(unit_t width, unit_t height);
    void end();
    void text(unit_t x, unit_t y, std::string text, std::string colour = "black", std::string stroke = "black");
    void rect(unit_t x, unit_t y, unit_t width, unit_t height, std::string fill = "black", std::string stroke = "black");
}

#endif