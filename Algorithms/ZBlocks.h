//
// Created by savchenkoto on 19.03.18.
//

#ifndef LABS_ZBLOCKS_H
#define LABS_ZBLOCKS_H


#include "Algorithm.h"

class ZBlocks : public Algorithm {
private:

    const std::string SENTINEL = "$";

public:

    explicit ZBlocks(const std::string &str);

    std::vector<unsigned long> find(const std::string &pattern);

    ~ZBlocks() override = default;
};


#endif //LABS_ZBLOCKS_H
