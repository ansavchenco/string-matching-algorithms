//
// Created by savchenkoto on 18.03.18.
//

#ifndef LABS_KNUTHMORRISPRATT_H
#define LABS_KNUTHMORRISPRATT_H


#include "Algorithm.h"

class KnuthMorrisPratt : public Algorithm {
private:

    std::vector<std::pair<unsigned long, int>> pairs;

public:

    explicit KnuthMorrisPratt(std::string str);

    std::vector<unsigned long> find(const std::string &pattern) override;

    std::vector<unsigned long> qfind(const std::string &pattern);

    ~KnuthMorrisPratt() override;

};


#endif //LABS_KNUTHMORRISPRATT_H
