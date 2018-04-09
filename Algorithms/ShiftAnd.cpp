//
// Created by savchenkoto on 04.04.18.
//

#include "ShiftAnd.h"
#include <utility>

ShiftAnd::ShiftAnd() = default;

ShiftAnd::ShiftAnd(std::string text) : Algorithm(std::move(text)) {}


std::vector<unsigned long> ShiftAnd::find(const std::string &pattern) {

    unsigned long n = text.length();
    unsigned long m = pattern.length();
    auto hits = std::vector<unsigned long>();

    auto charBitMaps = std::vector<unsigned long>(ALPHABET_POWER, 0);
    for (unsigned long i = 0; i < m; i++) {
        charBitMaps[int(pattern[i])] |= 1 << (m - 1 - i);
    }

    unsigned long mostSignificantBit = 1 << (m - 1);
    unsigned long M = 0;
    for (unsigned long i = 0; i < n; i++) {
        M = (M >> 1 | mostSignificantBit) & charBitMaps[text[i]];
        if (M & 1) {
            hits.push_back(i - m + 1);
        }
    }
    return hits;

}


ShiftAnd::~ShiftAnd() = default;

