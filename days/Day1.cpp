#include "Day1.hpp"

void Day1::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day1.txt");

    std::vector<int> cals;
    int currentElf = 0;

    while (!inputStream.eof()) {
        std::string current;
        std::getline(inputStream,current);

        if(current.empty()) {
            cals.emplace_back(currentElf);
            currentElf = 0;
        } else {
            currentElf += std::stoi(current);
        }
    }

    std::ranges::sort(cals, std::ranges::greater());

    std::cout << cals[0] << "\n";
    std::cout << cals[0] + cals[1] + cals[2] << "\n";
}
