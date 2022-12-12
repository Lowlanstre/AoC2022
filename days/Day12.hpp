#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

class Day12 {
public:
    static void solve();
private:
    static bool climbable(int x,int y,char f, std::vector<std::string>& m);
};