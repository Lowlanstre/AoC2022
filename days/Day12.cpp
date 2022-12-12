#include "Day12.hpp"

void Day12::solve() {

    std::ifstream inputStream;
    inputStream.open("..\\input\\day12.txt");

    int partOne = 0, partTwo = 0;
    int steps = 0;

    std::vector<std::string> map;
    std::vector<std::pair<int,int>> offsets =
            {{-1,0},{1,0},{0,-1},{0,1}};
    std::set<std::pair<int,int>> layer;
    std::set<std::pair<int,int>> visited;

    while(!inputStream.eof()){
        std::string l;
        std::getline(inputStream,l);
        map.push_back(l);
    }

    for(int i = 0; i < map.size() && layer.empty(); ++i) {
        for(int j = 0; j < map.back().size(); ++j) {
            if(map[i][j] == 'E') {
                layer.emplace(i,j);
                visited.emplace(i,j);
            }
        }
    }

    while(partOne == 0) {
        std::set<std::pair<int,int>> layerBuffer;
        for(auto& e : layer) {

            for(auto &o : offsets) {
                int x = e.first+o.first, y = e.second+o.second;
                if(climbable(x,y,
                             map[e.first][e.second],map)) {
                    if(!visited.contains(std::make_pair(x,y))) {
                        visited.emplace(x,y);
                        layerBuffer.emplace(x,y);
                    }
                }
            }
            if(map[e.first][e.second] == 'S')
                partOne = steps;
            if(partTwo == 0 && map[e.first][e.second] == 'a')
                partTwo = steps;
        }
        layer = layerBuffer;
        ++steps;
    }
    std::cout << partOne << "\n";
    std::cout << partTwo << "\n";
}

bool Day12::climbable(int x, int y, char f, std::vector<std::string> &m) {

    if(f == 'E')
        f = 'z';
    if(x < 0 || y < 0 || x >= m.size() || y >= m.back().size())
        return false;
    if(m[x][y] == 'S')
        return 'a'-f >= -1;
    if(m[x][y] == 'E')
        return 'z'-f >= -1;
    return m[x][y]-f >= -1;
}
