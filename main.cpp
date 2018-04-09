#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Algorithms/KnuthMorrisPratt.h"
#include "Utils/FileUtils.h"
#include "Algorithms/BoyerMoore.h"
#include "Algorithms/RabinKarp.h"
#include "Utils/Bitwise.h"
#include "Algorithms/ShiftAnd.h"


using namespace std;

string getContext(const string &str, unsigned long index, unsigned long pLen, int contextSize = 20) {
    long start;
    long len;
    if (index < contextSize) {
        start = 0;
    } else {
        start = index - contextSize;
    }
    if (index + contextSize + pLen > str.length()) {
        len = str.length() - start;
    } else {
        len = pLen + (contextSize * 2);
    }
    string sub = str.substr(start, len);
//    replace(sub.begin(), sub.end(), char(10), ' ');
//    replace(sub.begin(), sub.end(), char(13), ' ');
    return sub;
}

void display(vector<unsigned long> hits, const string &str, unsigned long pLen, unsigned long stop = 0,
             int contextSize = 20) {
    vector<unsigned long>::iterator it;
    unsigned long counter = 0;
    cout << "=================================================================" << endl;
    for (it = hits.begin(); it != hits.end() && (counter < stop || stop == 0); it++) {
        string sub = getContext(str, *it, pLen, contextSize);
        cout << "Index: " << *it << endl;
        cout << "..." << sub << "..." << endl;
        cout << "=================================================================" << endl;
        counter++;
    }
    cout << hits.size() << " results were found:" << endl;
}




void test(vector<pair<string, string>> testFiles) {
    cout << "=================================================================" << endl;
    cout << "                            Tests" << endl;
    cout << "=================================================================" << endl;
    vector<pair<string, string>>::iterator it;


    for (it = testFiles.begin(); it != testFiles.end(); it++){
        string t = FileUtils::readWhole("../Examples/" + it->first);
        string p = FileUtils::readWhole("../Examples/" + it->second);

        KnuthMorrisPratt *kmp = new KnuthMorrisPratt(t);
        RabinKarp rabinKarp = RabinKarp(t, 72057594037928017, 9);
        ShiftAnd shiftAnd = ShiftAnd(t);

        auto start = chrono::high_resolution_clock::now();
        vector<unsigned long> KMPHits = kmp->find(p);
        auto end = chrono::high_resolution_clock::now();
        auto KMPTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

        unsigned long collisionsCount = 0;
        start = chrono::high_resolution_clock::now();
        vector<unsigned long> rkHits = rabinKarp.find(p, collisionsCount, false);
        end = chrono::high_resolution_clock::now();
        auto rkTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

//        collisionsCount = 0;
//        start = chrono::high_resolution_clock::now();
//        vector<unsigned long> rkeHits = rabinKarp.find(p, collisionsCount, true);
//        end = chrono::high_resolution_clock::now();
//        auto rkeTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

        start = chrono::high_resolution_clock::now();
        vector<unsigned long> saHits = shiftAnd.find(p);
        end = chrono::high_resolution_clock::now();
        auto saTime = chrono::duration_cast<chrono::nanoseconds>(end - start);


        cout << "Text:            " << it->first << " (" << t.length() << ")" << endl;
        cout << "Pattern:         " << it->second << " (" << p.length() << ")" << endl;
        cout << "Occurrences:     " << endl;
        cout << "  K-M-P:         " << KMPHits.size() << endl;
        cout << "  Rabin-Karp:    " << rkHits.size() << " (collisions count: " << collisionsCount << ")" << endl;
//        cout << "  Rabin-Karp-er: " << rkeHits.size() << " (collisions count: " << collisionsCount << ")" << endl;
        cout << "  Shift-And:     " << saHits.size() << endl;
        cout << "Time:            " << endl;
        cout << "  K-M-P:         " << (double)KMPTime.count() / 1000000000 << endl;
        cout << "  Rabin-Karp:    " << (double)rkTime.count() / 1000000000 << endl;
//        cout << "  Rabin-Karp-er :" << (double)rkeTime.count() / 1000000000 << endl;
        cout << "  Shift-And:     " << (double)saTime.count() / 1000000000 << endl;
        cout << "=================================================================" << endl;
    }
}

vector<unsigned long> getMismatches(vector<unsigned long> hits1, vector<unsigned long> hits2) {
    vector<unsigned long>::iterator it;
    vector<unsigned long> mismatches;
    for (it = hits1.begin(); it != hits1.end(); it++) {
        if(find(hits2.begin(), hits2.end(), *it) == hits2.end()) {
              mismatches.push_back(*it);
        }
    }
    return mismatches;
}



vector<pair<string, string>> tests = {


//        {make_pair("rand100mln", "rand10mln")},

//        {make_pair("dna10mln.txt", "dna10")},
        {make_pair("abc1mln", "abc5")},
        {make_pair("abc1mln", "abc10")},
        {make_pair("abc1mln", "abc20")},
        {make_pair("abc10mln", "abc5")},
        {make_pair("abc10mln", "abc10")},
        {make_pair("abc10mln", "abc20")},
        {make_pair("abc100mln", "abc5")},
        {make_pair("abc100mln", "abc10")},
        {make_pair("abc100mln", "abc20")},


//        {make_pair("exm2", "pat2")},
//        {make_pair("abra-exm", "abra-pat")},
//        {make_pair("exm3", "pat4")},
//        {make_pair("exm1", "exm1")},
//        {make_pair("exm1", "pat1")},
//        {make_pair("1mln(a).txt", "100thd(a).txt")},
//        {make_pair("rand10mln", "rand1mln")},
//        {make_pair("100mln(a).txt", "10mln(a).txt")},
//        {make_pair("100mln(a).txt", "1mln(a).txt")},
//        {make_pair("100mln(a).txt", "100thd(a).txt")},
//        {make_pair("dna100mln.txt", "dna10")},
//        {make_pair("dna100mln.txt", "dna20")},
//        {make_pair("dna100mln.txt", "dna30")},
//        {make_pair("dna50thd.txt", "dna30")},
//        {make_pair("dna100thd.txt", "dna30")},
//        {make_pair("dna500thd.txt", "dna30")},
//        {make_pair("dna500thd.txt", "dna10")},
//        {make_pair("dna100mln.txt", "dna10mln.txt")},
//        {make_pair("dna100mln.txt", "dna1mln.txt")},
//        {make_pair("dna100mln.txt", "dna500thd.txt")},
//        {make_pair("dna100mln.txt", "dna100thd.txt")},

};


unsigned long modulo(unsigned long x, unsigned long q) {
    return x % q;
}

int main() {
    test(tests);

//    unsigned long a = 65540;
//    cout << Bitwise::mod65535(a);

//    a = Bitwise::power(10);
//    getchar();

//    cout << Bitwise::power(2, 0);
//    unsigned long x = 2;
//    cout << x  << endl;
//    cout << (x << (29 - 1)) << endl;
//    cout << x;



//    auto start = chrono::high_resolution_clock::now();
//    modulo(65540, 65535);
//    auto end = chrono::high_resolution_clock::now();
//    auto bitTime = chrono::duration_cast<chrono::nanoseconds>(end - start);
//
//    start = chrono::high_resolution_clock::now();
//    Bitwise::mod65535(65540);
//    end = chrono::high_resolution_clock::now();
//    auto stdTime = chrono::duration_cast<chrono::nanoseconds>(end - start);
////
//    cout << "tests:" << endl;
//    cout << "stdTime: " << stdTime.count() << endl;
//    cout << "bitTime: " << bitTime.count() << endl;


//    unsigned long maximum 18446744073709551615
//    unsigned long maximum 2305843009213693951

//    2 powers of n:
//     stdTime: 9603
//     bitTime: 74


//
//    cout << Mod(5, 3);

//    unsigned long n = 7;
//    for (int i = (sizeof(long) * 8) - 1; i > - 1  ; i--) {
//        long mask =  1 << i;
//        long masked_n = n & mask;
//        long thebit = masked_n >> i;
//        cout << thebit;
//    }




//    FileUtils::random("rand100mln", 100000000);
//    FileUtils::random("rand1mln", 1000000);
//    FileUtils::random("abc10mln", 10000000, "abc");
//    FileUtils::random("abc100mln", 100000000, "abc");
//    FileUtils::random("abc1mln", 1000000, "abc");
//    FileUtils::random("abc10", 10, "abc");
//    FileUtils::random("abc20", 20, "abc");
//    FileUtils::random("abc5", 5, "abc");
//    FileUtils::random("dna20", "acgt", 20);
//    FileUtils::random("dna30", "acgt", 30);

//    string t = "abracadabra";
//    string t = "abcdeftrdefefrdef";
//    string t = "rdefabcdeffrdefefrdef";
//    string t = "rdefabcdefardefefrdef";
//    string t = "hellellellellelle";
//    string p = "elle";
//    string p = "bra";

//    string t = FileUtils::readWhole("../Examples/dna50thd.txt");
//    string p = FileUtils::readWhole("../Examples/dna30");

//    RabinKarp rk = RabinKarp(t, 35184372088891, 2);
//    display(rk.find(p), t, p.length());

//    BoyerMoore bm = BoyerMoore(t);
//    display(bm.find(p), t, p.length());

//    ShiftAnd sa = ShiftAnd(t);
//    display(sa.find(p), t, p.length());


}