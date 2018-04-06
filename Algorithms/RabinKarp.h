//
// Created by savchenkoto on 31.03.18.
//

#ifndef LABS_RABINKARP_H
#define LABS_RABINKARP_H


#include <vector>
#include <string>
#include "Algorithm.h"

class RabinKarp : public Algorithm {
private:

    const unsigned long q;

    const unsigned long x;

    long gornerMod(std::vector<long> seq, unsigned long q, unsigned int power = 2);

    unsigned long initHash(const std::string &str, unsigned long windowSize = 0);

    void recalculateHash(long &hash, unsigned long factor, unsigned long index, std::string str,
                         unsigned long windowSize);

public:

    RabinKarp(unsigned long q, unsigned long x);

    explicit RabinKarp(std::string text, unsigned long q, unsigned long x);

    std::vector<unsigned long> find(const std::string &pattern, unsigned long &collisionsCount);

    std::vector<unsigned long> find(const std::string &pattern) override;

};


#endif //LABS_RABINKARP_H
