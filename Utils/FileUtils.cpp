//
// Created by savchenkoto on 19.03.18.
//

#include <fstream>
#include <sstream>
#include "FileUtils.h"


void FileUtils::repeat(const std::string &filename, const std::string &sequence, const unsigned long &count) {

    std::ofstream outfile;
    outfile.open("../Examples/" + filename, std::ios_base::app);

    for (unsigned long i = 0; i < count; i++) {
        outfile << sequence;
    }
    outfile.close();

}

void FileUtils::random(const std::string &filename, const unsigned long &count, const std::string &set, unsigned long lineLength) {

    std::ofstream outfile;
    outfile.open("../Examples/" + filename, std::ios_base::app);
    srand((time(0)));

//    std::string s = std::to_string(number);
//    char const *pchar = s.c_str();

    if (set == "") {
        int k = 0;
        std::string newSet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (unsigned long i = 0; i < count; i++) {
            outfile << newSet[rand() % newSet.length()];
            k++;
            if (k == lineLength) {
                outfile << '\n';
                k = 0;
            }
        }
    } else {
        int k = 0;
        for (unsigned long i = 0; i < count; i++) {
            outfile << set[rand() % set.length()];
            k++;
            if (k == lineLength) {
                outfile << '\n';
                k = 0;
            }
        }
    }
    outfile.close();

}

std::string FileUtils::readWhole(const std::string &path) {

    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();

}
