#include "Histogram.hpp"
#include "libsvgc++.hpp"
#include <algorithm>

Histogram::Histogram() {
    this->input_info();
    this->check_validation();
    if (state != Error) {
        this->input_numbers();
        this->find_minmax();
        this->eval_bins();
        this->print_histogram();
    }
}

void Histogram::input_info() {
    std::cerr << "Enter number count: ";
    std::cin >> num_count;
    std::cerr << "Enter bin count: ";
    std::cin >> bin_count;
    std::cerr << "Enter step: ";
    std::cin >> scale_step;
}

void Histogram::check_validation() {
    if (scale_step < LOW_BOUND || scale_step > HIGH_BOUND)
        state = Error;
}

void Histogram::input_numbers() {
    bins = std::vector<num_t>(bin_count);
    nums = std::vector<num_t>(num_count);
    for (auto& num : nums)
    {
        std::cin >> num;
    }
}

void Histogram::find_minmax() {
    max_n = *std::max_element(nums.begin(),
                               nums.end());
    min_n = *std::min_element(nums.begin(),
                               nums.end());
}

void Histogram::eval_bins() {
    double diff = max_n - min_n;
    double bin_step = diff / bin_count;
    for (auto num : nums)
        for (ulong i = 0; i < bin_count; i++) {
            bool in_bin = (num >= min_n + bin_step * i) &&
                          (num < min_n + bin_step * (i + 1));
            bool last = i == bin_count - 1;
            if (in_bin || last) {
                bins[i]++;
                break;
            }
        }
}

void Histogram::print_histogram() {
    ulong max_count =
        *std::max_element(bins.begin(),
                           bins.end());

    svg::begin(X + MAX_SVG_WIDTH, Y + (bin_count + 2) * ROW_HEIGHT);

    svg::end();

}
