//
// Created by savchenkoto on 18.03.18.
//

#include "KnuthMorrisPratt.h"

#include <utility>
#include "Preprocessor.h"


KnuthMorrisPratt::KnuthMorrisPratt(std::string str) : Algorithm(std::move(str)) { }

std::vector<unsigned long> KnuthMorrisPratt::find(const std::string &pattern) {

    std::vector<unsigned long> hits = std::vector<unsigned long>();
    unsigned long n = text.length();
    unsigned long m = pattern.length();
    std::vector<unsigned long> bpm = Preprocessor::modifyPrefixesBorderArray(
            Preprocessor::prefixesBorderArray(pattern));

    unsigned long q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = bpm[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            hits.push_back(i - q + 1);
            q = bpm[q - 1];
        }
    }
    return hits;

}

std::vector<unsigned long> KnuthMorrisPratt::qfind(const std::string &pattern) {

    std::vector<unsigned long> hits = std::vector<unsigned long>();
    unsigned long n = text.length();
    unsigned long m = pattern.length();
    std::vector<unsigned long> bpm =
            Preprocessor::modifyPrefixesBorderArray(Preprocessor::prefixesBorderArray(pattern));

    pairs = Preprocessor::fastPairs(pattern, bpm);
//    auto matrix = Preprocessor::borderSymbolMatrix(pattern, bpm);

    unsigned long q = 0;
    for (int i = 0; i < n; i++) {
        if (q > 0 && pattern[q] != text[i]) {
            if (pairs[q - 1].second != 0) {
                q = pairs[bpm[q - 1]].first;
            } else {
                q = 0;
            }
//            q = matrix[q - 1][int(text[i])];
        }

        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            hits.push_back(i - q + 1);
            q = bpm[q - 1];
        }
    }
    return hits;

}

KnuthMorrisPratt::~KnuthMorrisPratt() = default;





