#include "Day2.hpp"

void Day2::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day2.txt");

    int partOne = 0, partTwo = 0;
    char first, second;

    while(inputStream >> first >> second) {

        int Ifirst = first - 'A';
        int Isecond = second - 'X';

        partOne += Isecond+1;
        if(Ifirst == Isecond)
            partOne += 3;
        else if((Ifirst+1) % 3 == Isecond)
            partOne += 6;

        switch(Isecond) {
            case 0:
                partTwo += 1 + (Ifirst + 2) % 3;
                break;
            case 1:
                partTwo += 4 + Ifirst;
                break;
            case 2:
                partTwo += 7 + (Ifirst+1) % 3;
                break;
        }
    }

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";

}
