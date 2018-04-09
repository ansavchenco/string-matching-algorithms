//
// Created by savchenkoto on 31.03.18.
//

#include <cmath>
#include <utility>
#include <iostream>
#include "RabinKarp.h"
#include "../Utils/Bitwise.h"

long RabinKarp::gornerMod(std::vector<long> seq, unsigned long q, unsigned int power) {

    long result = 0;
    unsigned long n = seq.size();
    for (unsigned long i = 0; i < n; i++) {
        result = (result * power * seq[i]) % q;
    }
    return result;

}

RabinKarp::RabinKarp(unsigned long _q, unsigned long _x) : q(_q), x(_x) {}

RabinKarp::RabinKarp(std::string text, unsigned long _q, unsigned long _x) : Algorithm(std::move(text)), q(_q), x(_x) {}


unsigned long RabinKarp::initHash(const std::string &str, unsigned long windowSize) {

    unsigned long hash = 0;
    if (windowSize == 0) {
        windowSize = str.length();
    }
    for (unsigned long i = 0; i < windowSize; i++) {
        hash = ((hash + int(str[i])) * x) % q;
    }
    return hash;

}

void RabinKarp::recalculateHash(long &hash, unsigned long factor, unsigned long index, std::string str,
                                unsigned long windowSize) {

    hash -= (long(str[index - 1]) * factor) % q;
    if (hash < 0) {
        hash += q;
    }
    hash = ((hash + int(str[index + windowSize - 1])) * x) % q;

}


std::vector<unsigned long> RabinKarp::find(const std::string &pattern, unsigned long &collisionsCount, bool errorable) {

    unsigned long n = text.length();
    unsigned long m = pattern.length();
    unsigned long factor = 1;
    for (unsigned long i = 0; i < m; i++) {
        factor = (factor * x) % q;
    }
    unsigned long patternHash = initHash(pattern);
    long windowHash = initHash(text, m);
    auto hits = std::vector<unsigned long>();

    collisionsCount = 0;
    for (unsigned long i = 0; i < n - m + 1; i++) {
        if (patternHash == windowHash) {
            if (!errorable) {
                unsigned long k = 0;
                bool match = false;
                while (k < m && pattern[k] == text[i + k]) {
                    k++;
                    if (k == m) {
                        hits.push_back(i);
                        match = true;
                    }
                }
                if (!match) {
                    collisionsCount++;
                }
            } else {
                hits.push_back(i);
            }
        }

        windowHash -= (long(text[i]) * factor) % q;
        if (windowHash < 0) {
            windowHash += q;
        }
        windowHash = ((windowHash + long(text[i + m])) * x) % q;

    }
    return hits;

}

std::vector<unsigned long> RabinKarp::find(const std::string &pattern) {
    return std::vector<unsigned long>();
}





