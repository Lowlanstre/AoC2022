#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Day7 {
public:
    static void solve();
};

class Dir {

    typedef long long ll;
    typedef std::pair<ll,std::string> file;

public:

    explicit Dir(std::string n) {
        this->name = std::move(n);
    }

    ll value = 0;
    std::string name;
    Dir* above = nullptr;
    std::vector<Dir*> sub;
    std::vector<file> files;

};