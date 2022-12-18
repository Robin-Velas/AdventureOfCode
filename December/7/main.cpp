#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Node
{
public:
    Node()
    {
        parent = nullptr;
        name = "";
        size = 0;
    }
    Node *parent;
    std::vector<Node> children;
    std::string name;
    int size;
};
// input is lines
Node parse(std::vector<std::string> lines)
{
    Node head;
    int i = 0;
    head.size = 0;
    while(i < lines.size()) {
        if (lines[i].substr(0, 1).compare("$") == 0) {
            // this is a command
            std::string command = lines[i].substr(2, 2);
            if (command.compare("cd")) {
                //differenciate ".." and "folder"
                if (lines[i].substr(5, 2).compare("..") == 0) {
                    // go up one level 
                } else {
                   //recusively go down one level and add the size of the folder to the parent
                   auto tmp = std::vector<std::string>(lines.begin() + i + 1, lines.end());
                   head.size += parse(tmp).size;
                }
            }
        } else {
            //it's either a folder or a file
            if (lines[i].substr(0, 1).compare("d") == 0) {
                //it's a folder
                Node folder;
                folder.name = lines[i].substr(5, lines[i].length() - 5);
                folder.size = 0;
                folder.parent = &head;
                head.children.push_back(folder);
                head.size += folder.size;
            } else {
                //it's a file
                Node file;
                //get the first int in the string
                int j = 0;
                while (lines[i].substr(j, 1).compare(" ") != 0) {
                    j++;
                }
                file.size = std::stoi(lines[i].substr(0, j));
                file.parent = &head;
                head.children.push_back(file);
                head.size += file.size;
            }
        }
    }
    return head;
}

int find(Node head, int size) {
    int count = 0;
    if (head.size <= size) {
        count++;
    }
    for (int i = 0; i < head.children.size(); i++) {
        count += find(head.children[i], size);
    }
    return count;
}

int main()
{
    std::ifstream file("input.txt");
    std::string str;
    std::vector<std::string> lines;
    while (std::getline(file, str))
    {
        lines.push_back(str);
    }
    Node head = parse(lines);
    int sizeUnder1000000 = find(head, 1000000);

    std::cout << sizeUnder1000000 << std::endl;

    return 0;
}

