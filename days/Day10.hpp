#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Day10 {
public:
    static void solve();
private:
    static void calcCycle(int r, int& c, int& res, std::string& s);
};