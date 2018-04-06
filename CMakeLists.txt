cmake_minimum_required(VERSION 3.9)
project(labs)

set(CMAKE_C_FLAGS "-jgmp" "-lgmpxx")

set(CMAKE_CXX_STANDARD 11)

add_executable(labs main.cpp
        Algorithms/Algorithm.cpp Algorithms/Algorithm.h Algorithms/KnuthMorrisPratt.cpp Algorithms/KnuthMorrisPratt.h Algorithms/Preprocessor.cpp Algorithms/Preprocessor.h Utils/FileUtils.cpp Utils/FileUtils.h Algorithms/Prefixes.cpp Algorithms/Prefixes.h Algorithms/ZBlocks.cpp Algorithms/ZBlocks.h Algorithms/BoyerMoore.cpp Algorithms/BoyerMoore.h Algorithms/RabinKarp.cpp Algorithms/RabinKarp.h Utils/Bitwise.cpp Utils/Bitwise.h Algorithms/ShiftAnd.cpp Algorithms/ShiftAnd.h)
