#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>

#include "libsvgc++.hpp"

using num_t = unsigned long;
using ulong = unsigned long;
class Histogram {
    const ulong EXTRA_X = 100;
    const ulong STEP_LOW_BOUND = 4;
    const ulong STEP_HIGH_BOUND = 9;
    const ulong X = 50;
    const ulong Y = 50;
    const ulong MAX_SVG_WIDTH = 500;
    const ulong MAX_CAPTION_WIDTH = 50;
    const ulong LETTER_LENGTH = 8;
    const ulong MAX_ROW_WIDTH = MAX_SVG_WIDTH - MAX_CAPTION_WIDTH;
    const ulong ROW_HEIGHT = 25;
    const ulong ROW_UNIT = 5;
    const ulong MAX_ROW_UNITS = MAX_ROW_WIDTH / ROW_UNIT;
    const ulong CAPTION_SHIFT_X = 5;
    const ulong CAPTION_SHIFT_Y = 18;
    const ulong SCALE_SHIFT_Y = 5;
    const ulong SCALE_CAPTION_SHIFT_Y = 15;
    const ulong SCALE_CAPTION_SHIFT_X = 3;

    num_t num_count, bin_count, scale_step,
          max_n, min_n;
    std::vector<num_t> nums, bins;
    enum HistogramState {InProgress, Error, Done} state;
    std::vector<std::string> colours{"#6495ED", "#FF7F50", "#D2691E", "#8A2BE2", 
                                     "#7FFFD4", "#DC143C", "#006400", "#FF8C00", 
                                     "#F0E68C", "#90EE90", "#20B2AA", "#00FF7F", 
                                     "#4682B4", "#FF6347", "#EE82EE", "#735184"};

    void input_info();
    void check_validation();
    void input_numbers();
    void find_minmax();
    void eval_bins();
    void print_histogram();
    std::string get_colour();
public:
    Histogram();
};

#endif
