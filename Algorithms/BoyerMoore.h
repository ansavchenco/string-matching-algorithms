//
// Created by savchenkoto on 23.03.18.
//

#ifndef LABS_BOYERMOORE_H
#define LABS_BOYERMOORE_H

#include <string>
#include <list>
#include "Algorithm.h"

class BoyerMoore : public Algorithm {
private:

    const unsigned long ALPHABET_POWER;

    std::vector<std::vector<unsigned long>> buildBadSymbolTable(const std::string &str);

    std::vector<unsigned long> buildGoodSuffixTable(const std::string &str);

public:

    explicit BoyerMoore(std::string text, unsigned long alphabetPower = 256);

    std::vector<unsigned long> find(const std::string &pattern) override;

    std::vector<unsigned long> badSymbolFind(const std::string &pattern);

    std::vector<unsigned long> goodSuffixFind(const std::string &pattern);

    ~BoyerMoore() override;

};


#endif //LABS_BOYERMOORE_H
