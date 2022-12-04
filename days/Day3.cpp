#include "Day3.hpp"

int Day3::trans(char& c) {
    if(c >= 'A' && c <= 'Z')
        return c - 38;
    return c - 96;
}

void Day3::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day3.txt");

    int partOne = 0;
    int partTwo = 0;

    std::vector<std::string> group;

    while(!inputStream.eof()) {

        std::string rucksack,left,right;
        std::getline(inputStream,rucksack);

        left = rucksack.substr(0,rucksack.length()/2);
        right = rucksack.substr(rucksack.length()/2,rucksack.length());

        for(auto& c : left) {

            if(right.find(c) != std::string::npos) {
                partOne += trans(c);
                break;
            }
        }

        group.emplace_back(rucksack);

        if(group.size() == 3) {

            for(auto& c : group.at(0)) {
                if(group.at(1).find(c) != std::string::npos
                && group.at(2).find(c) != std::string::npos) {
                    partTwo += trans(c);
                    group.clear();
                    break;
                }
            }
        }
    }

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";
}
