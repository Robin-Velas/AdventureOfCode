#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

int checkVisibleTrees(std::vector<std::vector<int>> matrice, int i, int j) {
    
    bool visibleTrees = true;
    int treeHeight = matrice[i][j];
    //check north
    for (int k = i - 1; k >= 0; k--) {
        if (matrice[k][j] >= treeHeight) {
            visibleTrees = false;
            break;
        }
    }
    if (visibleTrees) {
        return 1;
    }
    visibleTrees = true;
    //check south
    for (int k = i + 1; k < matrice.size(); k++) {
        if (matrice[k][j] >= treeHeight) {
            visibleTrees = false;
            break;
        }
    }

    if (visibleTrees) {
        return 1;
    }
    visibleTrees = true;

    //check west
    for (int k = j - 1; k >= 0; k--) {
        if (matrice[i][k] >= treeHeight) {
            visibleTrees = false;
            break;
        }
    }

    if (visibleTrees) {
        return 1;
    }
    visibleTrees = true;
    //check east
    for (int k = j + 1; k < matrice[i].size(); k++) {
        if (matrice[i][k] >= treeHeight) {
            visibleTrees = false;
            break;
        }
    }
    
    return visibleTrees ? 1 : 0;
}
int treeScenicScore(std::vector<std::vector<int>> matrice, int i, int j) {
    int tmpTreeHeight = matrice[i][j];

    //check north
    int scoreN = 0;
    for (int k = i - 1; k >= 0; k--) {
        scoreN++;
        if (matrice[k][j] >= tmpTreeHeight) {
            break;
        }
    }

    //check south
    int scoreS = 0;
    for (int k = i + 1; k < matrice.size(); k++) {
        scoreS++;
         if (matrice[k][j] >= tmpTreeHeight) {
            break;
        }
    }

    //check west
    int scoreW = 0;
    for (int k = j - 1; k >= 0; k--) {
        scoreW++;
        if (matrice[i][k] >= tmpTreeHeight) {
            break;
        }
    }

    //check east
    int scoreE = 0;
    for (int k = j + 1; k < matrice[i].size(); k++) {
        scoreE++;
        if (matrice[i][k] >= tmpTreeHeight) {
            break;
        }
    }

    return scoreN * scoreS * scoreW * scoreE;
}




int part1(std::vector<std::vector<int>> matrice) {
    int visibleTrees = 0;
    for (int i = 0; i < matrice.size(); i++) {
        for (int j = 0; j < matrice[i].size(); j++) {
            visibleTrees += checkVisibleTrees(matrice, i, j);
        }
    }
    return visibleTrees;
}

int part2(std::vector<std::vector<int>> matrice) {
    int maxScore = 0;
    for (int i = 0; i < matrice.size(); i++) {
        for (int j = 0; j < matrice[i].size(); j++) {
            maxScore = std::max(maxScore, treeScenicScore(matrice, i, j));
        }
    }
    return maxScore;
}
int main() {
    std::ifstream file("input.txt");
    std::string str;
    std::vector<std::string> 
    lines;
    while (std::getline(file, str)) {
        lines.push_back(str);
    }
    //create a matrice from the input. each char is a number
    std::vector<std::vector<int>> matrice;

    for (int i = 0; i < lines.size(); i++) {
        std::vector<int> tmp;
        for (int j = 0; j < lines[i].size(); j++) {
            tmp.push_back(lines[i][j] - '0');
        }
        matrice.push_back(tmp);
    }

    int visibleTrees = part1(matrice);
    std::cout << visibleTrees << std::endl;

    int maxScore = part2(matrice);
    std::cout << maxScore << std::endl;
}