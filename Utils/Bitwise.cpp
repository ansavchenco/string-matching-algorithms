//
// Created by savchenkoto on 04.04.18.
//

#include "Bitwise.h"

unsigned long Bitwise::power(unsigned long x, unsigned long n) {

    unsigned long result = 1;
    if (n > 0) {
        result = x << (n - 1);
    }
    return result;

}



