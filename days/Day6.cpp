#include "Day6.hpp"

void Day6::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day6.txt");

    int partOne = 0, partTwo = 0;

    std::string buffer;
    std::getline(inputStream,buffer);

    partOne = funique(buffer,4);
    partTwo = funique(buffer,14);

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";

}

int Day6::funique(std::string s, int l) {
    std::set<int> marker;
    for(int i = 0;i < s.length(); ++i) {
        marker.clear();
        for(int j = 0; j < l; ++j) {
            marker.emplace(s[i+j]);
        }
        if(marker.size() == l)
            return i+l;
    }
    return -1;
}
