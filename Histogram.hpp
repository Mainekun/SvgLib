#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "libsvgc++.hpp"

using num_t = unsigned long;
using ulong = unsigned long;
class Histogram {
    const ulong LOW_BOUND = 4;
    const ulong HIGH_BOUND = 9;
    const ulong X = 50;
    const ulong Y = 50;
    const ulong MAX_SVG_WIDTH = 500;
    const ulong MAX_CAPTION_WIDTH = 50;
    const ulong LETTER_LENGTH = 8;
    const ulong MAX_ROW_WIDTH = MAX_SVG_WIDTH - MAX_CAPTION_WIDTH;
    const ulong ROW_HEIGHT = 25;
    const ulong ROW_UNIT = 5;

    num_t num_count, bin_count, scale_step,
          max_n, min_n;
    std::vector<num_t> nums, bins;
    enum HistogramState {InProgress, Error, Done} state;
    std::queue<char*> colours();

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
