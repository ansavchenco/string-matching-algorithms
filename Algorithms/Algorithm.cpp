//
// Created by savchenkoto on 18.03.18.
//

#include "Algorithm.h"

Algorithm::Algorithm() = default;

Algorithm::Algorithm(std::string str) : text(std::move(str)) {}

void Algorithm::update(std::string str) {
    this->text = str;
}

Algorithm::~Algorithm() = default;
