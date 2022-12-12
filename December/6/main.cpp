#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>

using namespace std;

bool isUnique(string iss);
void findFirstUniqueString(int chars, string line);

int main() {
    //read input.txt
    ifstream input("input.txt");
    string line;
    //read first line
    getline(input, line);
    
    //part 1
    findFirstUniqueString(4, line);
    //part 2
    findFirstUniqueString(14, line);
   
}
void findFirstUniqueString(int chars, string line) {
    string s = line.substr(0, chars);

    // iterate over the char in the line and find the index of the first unique character
    for(int i = chars; i < line.length(); i++) {
        //if the character is unique
        if (isUnique(s)) {
            //print the index
            cout << i << endl;
            //exit the loop
            break;
        } else {
            //remove the first character from the string
            s = s.substr(1, chars-1);
            //add the next character to the string
            s += line[i];
        }
    }
}

bool isUnique(string s) {
    //create a vector of characters
    vector<char> v;
    //create a char variable
    char c;
    //while the string has characters
    while (s.length() > 0) {
        //get the first character
        c = s[0];
        //remove the first character from the string
        s = s.substr(1, s.length() - 1);
        //if the character is in the vector
        if (find(v.begin(), v.end(), c) != v.end()) {
            //return false
            return false;
        }
        //else
        else {
            //add the character to the vector
            v.push_back(c);
        }
    }
    return true;
}