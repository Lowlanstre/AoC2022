#include "Day7.hpp"

void Day7::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day7.txt");

    long long partOne = 0, partTwo = 0;
    std::vector<long long>directory_sizes;

    // Hardcode root directory for simplicity

    Dir* currentDir = new Dir("/");
    std::string firstline;
    std::getline(inputStream,firstline);

    while (!inputStream.eof()) {

        std::string instruction;
        std::vector<std::string> tokens;
        std::stringstream parseStream;

        std::getline(inputStream, instruction);
        parseStream << instruction;
        while (parseStream >> instruction)
            tokens.push_back(instruction);

        if(tokens[0] == "$" && tokens[1] == "cd") {
            if(tokens[2] == "..") {
                if(currentDir->above != nullptr)
                    currentDir = currentDir->above;
                continue;
            }
            for(int i = 0; i < currentDir->sub.size();++i) {
                if(currentDir->sub[i]->name == tokens[2]) {
                    currentDir = currentDir->sub[i];
                    break;
                }
            }
        } else if(tokens[0] == "dir") {
            bool exists = false;
            for(auto &d : currentDir->sub) {
                if(d->name == tokens[1]) {
                    exists = true;
                    break;
                }
            }
            if(!exists) {
                auto* temp = new Dir(tokens[1]);
                temp->above = currentDir;
                currentDir->sub.push_back(temp);
            }
        } else if(tokens[0] != "$") {
            bool exists = false;
            for(auto &f : currentDir->files) {
                if(f.second == tokens[1]) {
                    exists = true;
                    break;
                }
            }
            if(!exists) {
                currentDir->files.emplace_back(std::stoll(tokens[0]),tokens[1]);
            }
        }
    }
    while(currentDir->above != nullptr)
        currentDir = currentDir->above;

    while(!(currentDir->name == "/" && currentDir->value != 0)) {

        bool computed = true;

        // It kinda supposes that there is no directory, which was true at least for my
        // input. Should be easy to replace it with a proper condition if

        for(auto& d : currentDir->sub) {
            if(d->value == 0) {
                currentDir = d;
                computed = false;
                break;
            }
        }
        if(!computed)
            continue;
        for(auto& f  : currentDir->files) {
            currentDir->value += f.first;
        }
        for(auto& d  : currentDir->sub) {
            currentDir->value += d->value;
        }
        if(currentDir->value <= 100000)
            partOne += currentDir->value;
        directory_sizes.push_back(currentDir->value);
        if(currentDir->name != "/")
            currentDir = currentDir->above;
    }
    std::ranges::sort(directory_sizes);
    long long goal = 30000000 - (70000000 - directory_sizes.back());
    for(auto& s : directory_sizes) {
        if(s >= goal) {
            partTwo = s;
            break;
        }
    }
    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";
}