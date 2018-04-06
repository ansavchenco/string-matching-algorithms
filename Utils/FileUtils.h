//
// Created by savchenkoto on 19.03.18.
//

#ifndef LABS_FILEUTILS_H
#define LABS_FILEUTILS_H

#include <string>

class FileUtils {
public:

    static void repeat(const std::string &filename, const std::string &sequence, const unsigned long &count);

    static void random(const std::string &filename, const unsigned long &count, const std::string &set = "", unsigned long lineLength = 0);

    static std::string readWhole(const std::string &path);



};


#endif //LABS_FILEUTILS_H
