#ifndef STRINGSET_H_INCLUDED
#define STRINGSET_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <fstream>

class StringSet{
    public:
        std::vector<std::string> Vectstring;
        StringSet(const std::vector<std::string> init);
        StringSet();
        void Printer();
        void Add(std::string str);
        void Discard(std::string str);
        StringSet operator +(StringSet strset);
        StringSet operator *(StringSet strset);
        void Clear();
        int CountSet();
        double Sim(StringSet strset);
        StringSet intoSet(std::ifstream& fin1, std::string file_name);
};


#endif // STRINGSET_H_INCLUDED
