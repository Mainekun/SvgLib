#include "libsvgc++.hpp"

void fcout(std::string format...) {
    va_list args;
    va_start(args, format);

    bool input_format = false;
    for (auto i : format) {
        if (i == '%') {
            input_format = true;
            continue;
        }
        if (input_format) {
            switch (i)
            {
            case 'i':
                std::cout << va_arg(args, int);
                break;
            case 's':
                std::cout << va_arg(args, char*);
                break;
            case 'f':
                std::cout << va_arg(args, double);
                break;
            case 'c':
                std::cout << (char)va_arg(args, int);
                break;
            }
            input_format = false;
        }
        else {
            std::cout << i;
        }
    }

    va_end(args);
}

void fcerr(std::string format...) {
    va_list args;
    va_start(args, format);

    bool input_format = false;
    for (auto i : format) {
        if (i == '%') {
            input_format = true;
            continue;
        }
        if (input_format) {
            switch (i)
            {
            case 'i':
                std::cerr << va_arg(args, int);
                break;
            case 's':
                std::cerr << va_arg(args, char*);
                break;
            case 'f':
                std::cerr << va_arg(args, double);
                break;
            case 'c':
                std::cerr << (char)va_arg(args, int);
                break;
            }
            input_format = false;
        }
        else {
            std::cerr << i;
        }
    }

    va_end(args);
}

void svg::begin(unit_t width, unit_t height) {
    fcout("<?xml version='1.0' encoding='UTF-8' ?>\n");
    fcout("<svg width='%f' height='%f' viewBox='0 0 %f %f' xmlns='http://www.w3.org/2000/svg'>\n", width, height, width, height);
}

void svg::end() {
    fcout("</svg>");
}

void svg::text(unit_t x, unit_t y, std::string text, std::string colour = "black", std::string stroke = "black") {
    fcout("\t<text x='%f' y='%f' fill='%s' stroke='%s'>%s</text>\n", 
          x, y, colour.c_str(), stroke.c_str(), text.c_str());
}

void svg::rect(unit_t x, unit_t y, unit_t width, unit_t height, std::string fill = "black", std::string stroke = "black") {
    fcout("\t<rect x='%f' y='%f' width='%f' height='%f' fill='%s' stroke='%s' />\n", 
          x, y, width, height, fill.c_str(), stroke.c_str());
}