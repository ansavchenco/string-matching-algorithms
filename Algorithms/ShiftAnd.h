//
// Created by savchenkoto on 04.04.18.
//

#ifndef LABS_SHIFTAND_H
#define LABS_SHIFTAND_H


#include "Algorithm.h"

class ShiftAnd : public Algorithm {

private:

    unsigned int ALPHABET_POWER = 256;

public:

    ShiftAnd();

    explicit ShiftAnd(std::string text);

    std::vector<unsigned long> find(const std::string &pattern) override;

    ~ShiftAnd();

};


#endif //LABS_SHIFTAND_H
