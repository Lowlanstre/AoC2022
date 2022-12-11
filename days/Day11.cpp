#include "Day11.hpp"

void Day11::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day11.txt");

    long long partOne = 0, partTwo = 0;

    std::vector<Monkey> monkeys;

    while(!inputStream.eof()) {

        Monkey monkey;

        tokenizeLine(inputStream);
        auto items = tokenizeLine(inputStream);
        auto op = tokenizeLine(inputStream);
        auto div = tokenizeLine(inputStream);
        auto tr = tokenizeLine(inputStream);
        auto fa = tokenizeLine(inputStream);
        tokenizeLine(inputStream);

        for(int i = 2; i < items.size();++i)
            monkey.items.push_back(std::stoi(items[i]));
        if(op[4] == "+")
            if(op[5] == "old")
                monkey.mult = 2;
            else
                monkey.plus = std::stoi(op[5]);
        else
            if(op[5] == "old")
                monkey.pow = true;
            else
                monkey.mult = std::stoi(op[5]);
        monkey.divisor = std::stoi(div[3]);
        monkey.trueMonkey = std::stoi(tr[5]);
        monkey.falseMonkey = std::stoi(fa[5]);
        monkeys.push_back(monkey);

    }

    std::vector<long long> inspections(monkeys.size(),0);

    auto monkeysCopy = monkeys;

    for(int r = 0; r < 20; ++r) {
        for (int m = 0; m < monkeys.size(); ++m) {

            for (auto &i: monkeys[m].items) {
                ++inspections[m];
                i = monkeys[m].operation(i) / 3;
                if (i % monkeys[m].divisor == 0)
                    monkeys[monkeys[m].trueMonkey].items.push_back(i);
                else
                    monkeys[monkeys[m].falseMonkey].items.push_back(i);
            }
            monkeys[m].items.clear();
        }
    }

    std::ranges::sort(inspections);
    partOne = inspections.back() * inspections[inspections.size()-2];
    std::ranges::fill(inspections,0);

    monkeys = monkeysCopy;
    long long modulo = 1;
    for(auto&m : monkeys)
        modulo *= m.divisor;


    for(int r = 0; r < 10000; ++r) {
        for (int m = 0; m < monkeys.size(); ++m) {

            for (auto &i: monkeys[m].items) {
                ++inspections[m];
                i = monkeys[m].operation(i) % modulo;
                if (i % monkeys[m].divisor == 0)
                    monkeys[monkeys[m].trueMonkey].items.push_back(i);
                else
                    monkeys[monkeys[m].falseMonkey].items.push_back(i);
            }
            monkeys[m].items.clear();
        }
    }
    std::ranges::sort(inspections);
    partTwo = inspections.back() * inspections[inspections.size()-2];

    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";
}

std::vector<std::string> Day11::tokenizeLine(std::ifstream& f) {
    std::vector<std::string> r;
    std::string l;
    std::getline(f,l);
    std::erase(l,',');
    std::erase(l,':');
    std::stringstream s(l);
    while(s >> l)
        r.push_back(l);
    return r;
}


long long Monkey::operation(long long num) const {
    if(this->pow)
        return num*num;
    return num*this->mult + plus;
}
