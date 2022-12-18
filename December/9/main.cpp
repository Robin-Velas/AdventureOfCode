#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

struct MatriceVisited {
    // count up all of the positions the pos_T visited at least once with a value true
    
    std::vector<std::pair<int, int>> matrice;

    MatriceVisited() {
        matrice = {std::make_pair(0, 0)};
    }

    void deleteDuplicate() {
        std::sort(matrice.begin(), matrice.end());
        matrice.erase(std::unique(matrice.begin(), matrice.end()), matrice.end());
    }

    int count() {
        deleteDuplicate();
        return matrice.size();
    }
};

struct Bridge {
    std::pair <int, int> pos_T;
    std::pair <int, int> pos_B;
    MatriceVisited map_visited;

    Bridge() {
        pos_T = {0, 0};
        pos_B = {0, 0};
        map_visited = MatriceVisited();
    }

    void move(char dir, int dist) {
        for (int i = 0; i < dist; i++) {
            switch (dir) {
                case 'U':
                    pos_B.second++;
                    break;
                case 'D':
                    pos_B.second--;
                    break;
                case 'L':
                    pos_B.first--;
                    break;
                case 'R':
                    pos_B.first++;
                    break;
            }
            update_pos_T();
        }
    }

    void update_pos_T() {
        int rowDiff = pos_T.first - pos_B.first;
        int colDiff = pos_T.second - pos_B.second;

        if (std::abs(rowDiff) <= 1 && std::abs(colDiff) <= 1) return; // If head is one step up, down, left, or right from tail, do nothing
        
        if (rowDiff == 0 || colDiff == 0) {
            // If head is two steps up, down, left, or right from tail, move tail one step in that direction
            if (rowDiff == 2) pos_T.first -= 1;
            if (rowDiff == -2) pos_T.first += 1;
            if (colDiff == 2) pos_T.second -= 1;
            if (colDiff == -2) pos_T.second += 1;
        } else {
            // If head and tail aren't touching and aren't in the same row or column, move tail one step diagonally
            if (rowDiff > 0) pos_T.first -= 1;
            if (rowDiff < 0) pos_T.first += 1;
            if (colDiff > 0) pos_T.second -= 1;
            if (colDiff < 0) pos_T.second += 1;
        }

        map_visited.matrice.push_back(pos_T);
    }
};

int main() {
    std::ifstream file("input.txt");
    std::string str;
    std::vector<std::string> lines = {};
    while (std::getline(file, str)) {
        lines.push_back(str);
    }

    std::vector<std::pair<char, int>> pos_list = {};

    while (lines.size() > 0) {
        std::string line = lines[0];
        std::pair<char, int> pos = {line[0], 0};

        //from the 3rd char to the end, it's the number
        for (int i = 2; i < line.size(); i++) {
            pos.second *= 10;
            pos.second += line[i] - '0';
        }

        pos_list.push_back(pos);
        lines.erase(lines.begin());
    }

    Bridge bridge = Bridge();
    for (int i = 0; i < pos_list.size(); i++) {
        bridge.move(pos_list[i].first, pos_list[i].second);
    }   

    std::cout << bridge.map_visited.count() << std::endl;    
}   