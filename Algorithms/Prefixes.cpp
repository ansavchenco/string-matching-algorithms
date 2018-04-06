//
// Created by savchenkoto on 19.03.18.
//

#include "Prefixes.h"
#include "Preprocessor.h"

Prefixes::Prefixes(const std::string &str) : Algorithm(str) { }

std::vector<unsigned long> Prefixes::find(const std::string &pattern) {

    std::string str = pattern + SENTINEL + text;
    auto *hits = new std::vector<unsigned long>();
    std::vector<unsigned long> bp = Preprocessor::prefixesBorderArray(str);
    for (unsigned long i = pattern.length() + 1; i < str.length(); i++) {
        if (bp[i] == pattern.length()) {
            hits->push_back(i - (2 * pattern.length()));
        }
    }
    return *hits;

}

Prefixes::~Prefixes() = default;
