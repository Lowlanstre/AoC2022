#include "Day10.hpp"

void Day10::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day10.txt");

    int partOne = 0, registerX = 1, cycle = 0;
    std::string screen;

    while (!inputStream.eof()) {

        std::string instruction;
        std::getline(inputStream, instruction);
        std::stringstream ss(instruction);

        ss >> instruction;
        calcCycle(registerX, cycle, partOne, screen);
        if (instruction == "addx") {
            calcCycle(registerX, cycle, partOne, screen);
            ss >> instruction;
            registerX += std::stoi(instruction);
        }
    }
    std::cout << partOne << "\n";

    for(int i = 0; i < screen.size(); ++i) {
        if(i % 40 == 0)
            std::cout << "\n";
        std::cout << screen[i];
    }
}

void Day10::calcCycle(int r, int& c, int &res, std::string& s) {
    if(++c == 20 || (c-20) % 40  == 0 )
        res += c * r;
    if(std::abs(((c-1)%40)-r) <= 1)
        s = s.append("#");
    else
        s = s.append(".");
}
