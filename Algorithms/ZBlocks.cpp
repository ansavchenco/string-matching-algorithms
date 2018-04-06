//
// Created by savchenkoto on 19.03.18.
//

#include "ZBlocks.h"
#include "Preprocessor.h"


ZBlocks::ZBlocks(const std::string &str) : Algorithm(str) { }

std::vector<unsigned long> ZBlocks::find(const std::string &pattern) {

    std::string str = pattern + SENTINEL + text;
    auto *hits = new std::vector<unsigned long>();
    std::vector<unsigned long> blocks = Preprocessor::zBlocksArrayPrefixes(str);
    for (unsigned long i = pattern.length() + 1; i < str.length() ; i++) {
        if (blocks[i] == pattern.length()) {
            hits->push_back(i - pattern.length() - 1);
        }
    }
    return *hits;

}
