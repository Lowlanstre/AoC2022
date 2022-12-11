#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Day11 {
public:
    static void solve();
private:
    static std::vector<std::string> tokenizeLine(std::ifstream& f);
};

class Monkey {

public:
    std::vector<long long> items;

    int plus = 0;
    int mult = 1;
    bool pow = false;
    long long operation(long long num) const;

    int divisor;
    int trueMonkey;
    int falseMonkey;
};