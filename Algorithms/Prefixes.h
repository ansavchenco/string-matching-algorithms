//
// Created by savchenkoto on 19.03.18.
//

#ifndef LABS_PREFIXES_H
#define LABS_PREFIXES_H


#include "Algorithm.h"

class Prefixes : public Algorithm {
private:

    const std::string SENTINEL = "$";

public:

    explicit Prefixes(const std::string &str);

    std::vector<unsigned long> find(const std::string &pattern);

    ~Prefixes() override;
};


#endif //LABS_PREFIXES_H
