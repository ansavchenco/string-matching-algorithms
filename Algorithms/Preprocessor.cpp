//
// Created by savchenkoto on 18.03.18.
//

#include "Preprocessor.h"


unsigned long Preprocessor::cmp(const std::string &str, unsigned long p1, unsigned long p2) {

    unsigned long n = str.length();
    unsigned long result = 0;
    if (p1 < n && p2 < n && p1 >= 0 && p2 > 0 && p1 < p2) {
        unsigned long end;
        unsigned long i = 0;
        while (p1 < n && p2 < n && str[p1++] == str[p2++]) {
            i++;
        }
        result = i;
    }
    return result;
}

unsigned long Preprocessor::cmpReversed(const std::string &str, unsigned long p1, unsigned long p2) {

    unsigned long n = str.length();
    unsigned long result = 0;
    if (p1 < n && p2 < n && p1 >= 0 && p2 > 0 && p1 < p2) {
        unsigned long end;
        unsigned long i = 0;
        while (p1 >= 0 && p2 >= 0 && str[p1--] == str[p2--]) {
            i++;
        }
        result = i;
    }
    return result;

}


std::vector<unsigned long> Preprocessor::suffixesBorderArray(const std::string &str)    {

    unsigned long n = str.length();
    std::vector<unsigned long> bs(n);
    bs[n - 1] = 0;
    unsigned long t;
    for (long i = n - 2; i > -1; --i) {
        t = bs[i + 1];
        while (t > 0 && str[i] != str[n - t - 1]){
            t = bs[n - t];
        }
        if (str[i] == str[n - t - 1]) {
            bs[i] = t + 1;
        } else {
            bs[i] = 0;
        }
    }
    return bs;

}

std::vector<unsigned long> Preprocessor::modifySuffixesBorderArray(const std::vector<unsigned long> &bs) {

    unsigned long n = bs.size();
    std::vector<unsigned long> bsm(n);
    bsm[n - 1] = 0;
    bsm[0] = bs[0];
    for (unsigned long i = n - 2; i > 0; i--) {
        if (bs[i] && (bs[i] + 1 == bs[i - 1])) {
            bsm[i] = bsm[n - bs[i]];
        } else {
            bsm[i] = bs[i];
        }
    }
    return bsm;

}

std::vector<unsigned long> Preprocessor::prefixesBorderArray(const std::string &str) {

    unsigned long n = str.length();
    std::vector<unsigned long> bp(n);
    bp[0] = 0;
    unsigned long t;
    for (unsigned long i = 1; i < n; i++) {
        t = bp[i - 1];
        while (t > 0 && str[i] != str[t]){
            t = bp[t - 1];
        }
        if (str[i] == str[t]) {
            bp[i] = t + 1;
        } else {
            bp[i] = 0;
        }
    }
    return bp;

}

std::vector<unsigned long> Preprocessor::modifyPrefixesBorderArray(const std::vector<unsigned long> &bp) {

    unsigned long n = bp.size();
    std::vector<unsigned long> bpm(n);
    bpm[0] = 0;
    bpm[n - 1] = bp[n - 1];
    for (int i = 1; i < n - 1; i++) {
        if (bp[i] && (bp[i] + 1 == bp[i + 1])) {
            bpm[i] = bpm[bp[i] - 1];
        } else {
            bpm[i] = bp[i];
        }
    }
    return bpm;

}

std::vector<unsigned long> Preprocessor::zBlocksArrayPrefixes(const std::string &str) {

    unsigned long n = str.length();
    unsigned long l = 0;
    unsigned long r = 0;
    std::vector<unsigned long> z(n);
    z[0] = 0;
    for (unsigned long i = 1; i < n; i++) {
        z[i] = 0;
        if (i >= r) {
            z[i] = cmp(str, 0, i);
            l = i;
            r = l + z[i];
        } else {
            unsigned long k = i - l;
            if (z[k] < r - i) {
                z[i] = z[k];
            } else {
                z[i] = r - i + cmp(str, r - i, r);
                l = i;
                r = l + z[i];
            }
        }
    }
    return z;

}

std::vector<unsigned long> Preprocessor::zBlocksArraySuffixes(const std::string &str) {

    unsigned long n = str.length();
    long l = n - 1;
    long r = n - 1;
    std::vector<unsigned long> z(n, 0);
    z[0] = 0;
    for (long i = n - 2; i >= 0; i--) {
        if (i <= l) {
            z[i] = cmpReversed(str, i, n - 1);
            r = i;
            l = r - z[i];
        } else {
            unsigned long k = n - (r - i) - 1;
            if (z[k] < i - l) {
                z[i] = z[k];
            } else {
                z[i] = i - l + cmpReversed(str, l, n - i + l - 1);
                r = i;
                l = r - z[i];
            }
        }
    }
    return z;

}

std::vector<unsigned long> Preprocessor::zBlocksArrayReversed(const std::string &str) {

    unsigned long n = str.length();
    long l = n - 1;
    long r = n - 1;
    std::vector<unsigned long> z(n, 0);
    z[0] = 0;
    for (long i = n - 2; i >= 0; i--) {
        if (i <= l) {
            z[n - i - 1] = cmpReversed(str, i, n - 1);
            r = i;
            l = r - z[n - i - 1];
        } else {
            unsigned long k = n - (r - i) - 1;
            if (z[n - k - 1] < i - l) {
                z[n - i - 1] = z[n - k - 1];
            } else {
                z[n - i - 1] = i - l + cmpReversed(str, l, n - i + l - 1);
                r = i;
                l = r - z[n - i - 1];
            }
        }
    }
    return z;

}

unsigned long **Preprocessor::borderSymbolMatrix(const std::string &str, const std::vector<unsigned long> &bpm) {

    auto **bpm2 = new unsigned long*[str.length()];
    for (unsigned long i = 0; i < str.length(); i++) {
        bpm2[i] = new unsigned long[256];
    }
    for (unsigned long i = 0; i < str.length(); i++) {
        for (unsigned long j = 0; j < 256; j++) {
            if (bpm[i] > 0 && j == int(str[bpm[i]])) {
                bpm2[i][j] = bpm[i];
            } else {
                bpm2[i][j] = 0;
            }
        }
    }
    return bpm2;

}

std::vector<std::vector<unsigned long>>
Preprocessor::vectorSymbolMatrix(const std::string &str, const std::vector<unsigned long> &bpm) {

    std::vector<std::vector<unsigned long>> bpm2(str.length(), std::vector<unsigned long>(256, 0));
    for (unsigned long i = 0; i < str.length(); i++) {
        bpm2[i][int(str[bpm[i]])] = bpm[i];
    }
    return bpm2;

}

std::vector<std::pair<unsigned long, int>> Preprocessor::fastPairs(const std::string &str,
                                                                   const std::vector<unsigned long> &bpm) {

    auto pairs = std::vector<std::pair<unsigned long, int>>(str.length());

    for (unsigned long i = 0; i < str.length(); i++) {
        if (bpm[i] > 0) {
            pairs[i] = {bpm[i], int(str[bpm[i]])};
        } else {
            pairs[i] = {0, 0};
        }
    }
    return pairs;

}













