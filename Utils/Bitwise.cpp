//
// Created by savchenkoto on 04.04.18.
//

#include <cstdint>
#include "Bitwise.h"

unsigned long Bitwise::power(unsigned long x, unsigned long n) {

    unsigned long result = 1;
    if (n > 0) {
        result = x << (n - 1);
    }
    return result;

}

uint64_t Bitwise::mod65535(uint64_t a) {
    a = (a >> 16) + (a & 0xFFFF); /* sum base 2**16 digits */
    if (a < 65535) return a;
    if (a < (2 * 65535)) return a - 65535;
    return a - (2 * 65535);
}




