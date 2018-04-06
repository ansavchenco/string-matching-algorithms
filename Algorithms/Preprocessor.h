//
// Created by savchenkoto on 18.03.18.
//

#ifndef LABS_PREPROCESSOR_H
#define LABS_PREPROCESSOR_H

#include <string>
#include <vector>

class Preprocessor {
private :

    static unsigned long cmp(const std::string &str, unsigned long p1, unsigned long p2);

    static unsigned long cmpReversed(const std::string &str, unsigned long p1, unsigned long p2);

public:

    static std::vector<unsigned long> suffixesBorderArray(const std::string &str);

    static std::vector<unsigned long> modifySuffixesBorderArray(const std::vector<unsigned long> &bs);

    static std::vector<unsigned long> prefixesBorderArray(const std::string &str);

    static std::vector<unsigned long> modifyPrefixesBorderArray(const std::vector<unsigned long> &bp);

    static unsigned long **borderSymbolMatrix(const std::string &str, const std::vector<unsigned long> &bpm);

    static std::vector<std::vector<unsigned long>> vectorSymbolMatrix(const std::string &str, const std::vector<unsigned long> &bpm);

    static std::vector<std::pair<unsigned long, int>> fastPairs(const std::string &str,
                                                                const std::vector<unsigned long> &bpm);

    static std::vector<unsigned long> zBlocksArrayPrefixes(const std::string &str);

    static std::vector<unsigned long> zBlocksArraySuffixes(const std::string &str);

    static std::vector<unsigned long> zBlocksArrayReversed(const std::string &str);

};


#endif //LABS_PREPROCESSOR_H
