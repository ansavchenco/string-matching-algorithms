//
// Created by savchenkoto on 18.03.18.
//

#ifndef LABS_ALGORITHM_H
#define LABS_ALGORITHM_H

#include <string>
#include <vector>

class Algorithm {
protected:

    std::string text;

public:

    Algorithm();

    explicit Algorithm(std::string str);

    void update(std::string str);

    virtual std::vector<unsigned long> find(const std::string &pattern) = 0;

    virtual ~Algorithm();

};


#endif //LABS_ALGORITHM_H
