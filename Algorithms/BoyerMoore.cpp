//
// Created by savchenkoto on 23.03.18.
//

#include "BoyerMoore.h"
#include "Preprocessor.h"


BoyerMoore::BoyerMoore(std::string text, unsigned long alphabetPower) :
        Algorithm(std::move(text)), ALPHABET_POWER(alphabetPower) {}


std::vector<unsigned long> BoyerMoore::buildBadSymbolTable(const std::string &str) {

    unsigned long m = str.length();
    auto result = std::vector<unsigned long>(ALPHABET_POWER, m);
    for (unsigned long i = 0; i < m; i++) {
        result[int(str[i])] = m - 1 - i;
    }
    return result;

}

std::vector<unsigned long> BoyerMoore::buildGoodSuffixTable(const std::string &str) {

    unsigned long m = str.length();
    std::vector<unsigned long> zp = Preprocessor::zBlocksArrayPrefixes(str);
    std::vector<unsigned long> zs = Preprocessor::zBlocksArraySuffixes(str);
    auto result = std::vector<unsigned long>(m);

    unsigned long lastPrefixIndex = m;
    for (long i = m - 1; i > -1; i--) {
        if (zp[i] == m - i) {
            result[i] = lastPrefixIndex;
            lastPrefixIndex = i;
        } else {
            result[i] = lastPrefixIndex;
        }
    }
    result[m - 1] = 1;
    for (long i = 0; i < m - 1; i++) {
        if (zs[i] > 0) {
            result[m - 1 - zs[i]] = m - 1 - i;
        }
    }
    return result;

}

std::vector<unsigned long> BoyerMoore::find(const std::string &pattern) {

    auto hits = std::vector<unsigned long>();
    std::vector<unsigned long> badSymbolShift = buildBadSymbolTable(pattern);
    std::vector<unsigned long> goodSuffixShift = buildGoodSuffixTable(pattern);
    unsigned long m = pattern.length();
    unsigned long n = text.length();

    long bound = 0;
    unsigned long alignIndex = m - 1;
    while (alignIndex < n) {
        long i = alignIndex;
        long q = m - 1;
        while (q > -1 && q >= bound && pattern[q] == text[i]) {
            i--;
            q--;
        }
        if (q < bound) {
            hits.push_back(i + 1);
            bound = m - goodSuffixShift[0];
            q = 0;
        } else {
            bound = 0;
        }
//        alignIndex += std::max(badSymbolShift[text[i + 1]], goodSuffixShift[q]);
        alignIndex += goodSuffixShift[q];
    }
    return hits;

}


BoyerMoore::~BoyerMoore() = default;








