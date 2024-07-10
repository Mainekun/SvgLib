#include "libsvgc++.hpp"

int main() {
    svg::begin(400, 400);

    svg::rect(50, 100, 300, 100, "aquamarine", "white");
    svg::text(100,150,"SVG_LIB_H", "aquamarine", "black");

    svg::end();
}