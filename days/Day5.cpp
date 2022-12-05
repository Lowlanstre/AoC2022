#include "Day5.hpp"

void Day5::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day5.txt");

    std::string partOne, partTwo;
    int boxCount = 0;
    int count,source,dest;
    std::vector<std::string> boxRows;
    std::string currentLine;

    while (currentLine[1] != '1') {
        std::getline(inputStream, currentLine);
        boxRows.emplace_back(currentLine);
    }
    boxRows.pop_back();
    boxCount = currentLine[currentLine.length() - 1] - '0';
    std::vector<std::stack<char>> towers(boxCount);

    for (int i = 0; i < boxCount; ++i) {
        for (int j = boxRows.size()-1; j >= 0; --j) {
                char e = boxRows[j][(i * 4) + 1];
                if (e != ' ')
                    towers.at(i).push(e);
        }
    }
    std::getline(inputStream, currentLine);

    auto towersTwo = towers;

    while(!inputStream.eof()) {
        inputStream >> currentLine >> count >> currentLine
                    >> source >> currentLine >> dest;

        std::string buffer;

        for(int i = 0; i < count; ++i) {
            towers[dest-1].push(towers[source-1].top());
            towers[source-1].pop();
            buffer.push_back(towersTwo[source-1].top());
            towersTwo[source-1].pop();
        }
        std::ranges::reverse(buffer);
        for(auto& c : buffer)
            towersTwo[dest-1].push(c);
    }

    for(int i = 0; i < towers.size(); ++i) {
        partOne.push_back(towers[i].top());
        partTwo.push_back(towersTwo[i].top());
    }

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";

}
