#include "stats.h"
#include "math.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& numbers) {
    int i;
    Stats result{};

    if (numbers.empty()) {
        result.average = NAN;
        result.min     = NAN;
        result.max     = NAN;
        return result;
    }


    double sum = 0.0;
    double minVal = numbers[0];
    double maxVal = numbers[0];

    for (std::size_t i = 0; i < numbers.size(); i++) {
        double value = numbers[i];
        sum += value;

        if (value < minVal) {
            minVal = value;
        }
        if (value > maxVal) {
            maxVal = value;
        }
    }

    result.average = static_cast<float>(sum / numbers.size());
    result.min = static_cast<float>(minVal);
    result.max = static_cast<float>(maxVal);

    return result;
}