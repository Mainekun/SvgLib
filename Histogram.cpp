#include "Histogram.hpp"


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
    if (scale_step < STEP_LOW_BOUND || scale_step > STEP_HIGH_BOUND)
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

std::string Histogram::get_colour() {
    static std::deque<std::string> colours_queue{colours.begin(), colours.end()};
    std::string picked_colour = colours_queue.front();
    colours_queue.pop_front();
    colours_queue.push_back(picked_colour);
    return picked_colour;
}

void Histogram::print_histogram() {
    ulong max_count =
        *std::max_element(bins.begin(),
                           bins.end());
    
    svg::begin(X + MAX_SVG_WIDTH + EXTRA_X, 
               Y + (bin_count + 2) * ROW_HEIGHT);

    for (ulong i = 0; i < bins.size(); i++) {
        ulong text_alignment;
        if (bins[i] < 10) text_alignment = MAX_CAPTION_WIDTH - LETTER_LENGTH;
        else if (bins[i] < 100) text_alignment = MAX_CAPTION_WIDTH - 2 * LETTER_LENGTH;
        else text_alignment = MAX_CAPTION_WIDTH - 3 * LETTER_LENGTH;

        svg::text(X + text_alignment - CAPTION_SHIFT_X, 
                  Y + i * ROW_HEIGHT + CAPTION_SHIFT_Y, 
                  std::to_string(bins[i]), "black", "black");

        unit_t row_lenght;
        if (max_count > MAX_ROW_UNITS) row_lenght = (static_cast<double>(bins[i]) / max_count) * ROW_UNIT;
        else row_lenght = bins[i] * ROW_UNIT;

        svg::rect(X + MAX_CAPTION_WIDTH, 
                  Y + i * ROW_HEIGHT, 
                  row_lenght, ROW_HEIGHT, 
                  get_colour().c_str(), "black");
    }

    unit_t steps_count;
    if (max_count > MAX_ROW_UNITS) 
        steps_count = std::ceil(static_cast<double>(MAX_ROW_UNITS) / scale_step);
    else 
        steps_count = std::ceil(static_cast<double>(max_count) / scale_step);

    svg::rect(X + MAX_CAPTION_WIDTH,
              Y + ROW_HEIGHT * bins.size(),
              steps_count * scale_step * ROW_UNIT + 1, 1);
    
    for (ulong i = 0; i <= steps_count; i++)
        svg::rect(X + MAX_CAPTION_WIDTH + scale_step * ROW_UNIT * i, 
                  Y + ROW_HEIGHT * bins.size(),
                  1, SCALE_SHIFT_Y, "black", "black");

    num_t point;
    if (max_count > MAX_ROW_UNITS) point = std::floor(static_cast<double>(max_count) / MAX_ROW_UNITS);
    else point = scale_step;
    svg::text(X + MAX_CAPTION_WIDTH - SCALE_CAPTION_SHIFT_X, 
              Y + ROW_HEIGHT * bins.size() + SCALE_SHIFT_Y + SCALE_CAPTION_SHIFT_Y, "0");
    svg::text(X + MAX_CAPTION_WIDTH - SCALE_CAPTION_SHIFT_X + scale_step * ROW_UNIT,
              Y + ROW_HEIGHT * bins.size() + SCALE_SHIFT_Y + SCALE_CAPTION_SHIFT_Y, 
              std::to_string(static_cast<ulong>(point)));
    svg::text(X + MAX_CAPTION_WIDTH - SCALE_CAPTION_SHIFT_X + scale_step * steps_count,
              Y + ROW_HEIGHT * bins.size() + SCALE_SHIFT_Y + SCALE_CAPTION_SHIFT_Y,
              std::to_string(static_cast<ulong>(point * steps_count * scale_step)));
    //svg::text()

    svg::end();

}
