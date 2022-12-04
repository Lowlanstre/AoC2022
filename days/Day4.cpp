#include "Day4.hpp"

void Day4::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day4.txt");

    int partOne = 0;
    int partTwo = 0;

    char garbage;
    std::pair<int,int> elfOne{};
    std::pair<int,int> elfTwo{};

    while(!inputStream.eof()) {

        inputStream >> elfOne.first >> garbage >> elfOne.second >> garbage
                    >> elfTwo.first >> garbage >> elfTwo.second;

        bool predOne = elfOne.first >= elfTwo.first && elfOne.second <= elfTwo.second;
        bool predTwo = elfOne.first <= elfTwo.first && elfOne.second >= elfTwo.second;
        bool predThree = elfOne.second < elfTwo.first || elfTwo.second < elfOne.first;

        if(predOne || predTwo)
            ++partOne;
        if(!predThree)
            ++partTwo;

    }

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";
}
