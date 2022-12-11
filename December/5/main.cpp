//generic main
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>

///////////////////////////////////////////////
// this is the inputed stacks                //
///////////////////////////////////////////////
//     [G] [R]                 [P]           //
//     [H] [W]     [T] [P]     [H]           //
//     [F] [T] [P] [B] [D]     [N]           //
// [L] [T] [M] [Q] [L] [C]     [Z]           //
// [C] [C] [N] [V] [S] [H]     [V] [G]       //
// [G] [L] [F] [D] [M] [V] [T] [J] [H]       //
// [M] [D] [J] [F] [F] [N] [C] [S] [F]       //
// [Q] [R] [V] [J] [N] [R] [H] [G] [Z]       //
//  1   2   3   4   5   6   7   8   9        //
///////////////////////////////////////////////

using namespace std;
string part1(vector<string> lines, vector<stack<char>> stacks);
string part2(vector<string> lines, vector<stack<char>> stacks);
vector<stack<char>> generateStacks();
stack<char> createFromString(string s);
tuple<int, int, int> get_move_from_to(string line);

int main()
{
    //declare variables
    string line;
    vector<string> lines;
    ifstream myfile ("input.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            lines.push_back(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    vector<stack<char>> stacks = generateStacks();

    string ret = part1(lines, stacks);
    cout << "Part 1: " << ret << endl;
    ret = part2(lines, stacks);
    cout << "Part 2: " << ret << endl;
    return 0;
}

vector<stack<char>> generateStacks() {

    vector<stack<char>> stacks;
    stack<char> s1 = createFromString("QMGCL");
    stack<char> s2 = createFromString("RDLCTFHG");
    stack<char> s3 = createFromString("VJFNMTWR");
    stack<char> s4 = createFromString("JFDVQP");
    stack<char> s5 = createFromString("NFMSLBT");
    stack<char> s6 = createFromString("RNVHCDP");
    stack<char> s7 = createFromString("HCT");
    stack<char> s8 = createFromString("GSJVZNHP");
    stack<char> s9 = createFromString("ZFHG");

    stacks.push_back(s1);
    stacks.push_back(s2);
    stacks.push_back(s3);
    stacks.push_back(s4);
    stacks.push_back(s5);
    stacks.push_back(s6);
    stacks.push_back(s7);
    stacks.push_back(s8);
    stacks.push_back(s9);

    return stacks;
}

stack<char> createFromString(string s)
{
    stack<char> ret;
    for (int i = 0; i < s.size(); i++)
    {
        ret.push(s[i]);
    }
    return ret;
}

string part1(vector<string> lines, vector<stack<char>> stacks)
{
    string ret = "";
    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        tuple<int, int, int> pos = get_move_from_to(line);
        int from = get<0>(pos) - 1; //stacks are 0 indexed
        int to = get<1>(pos) - 1; //stacks are 0 indexed
        int move = get<2>(pos);

        for (int j = 0; j < move; j++)
        {
            char c = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(c);
        }
    }
    //take the first char from each stack
    for (int i = 0; i < stacks.size(); i++)
    {
        ret += stacks[i].top();
    } 
    return ret;
}

tuple<int, int, int> get_move_from_to(string line)
{
    int from, to , move = 0;
    string fromstr, tostr, movestr = "";

    int i = 5;
    //move, from, to
    while (line[i] != ' ')
    {
        movestr += line[i];
        i++;
    }
    //get index of from
    int idxfrom = line.find("from");
    i = idxfrom + 5;
    while (line[i] != ' ')
    {
        fromstr += line[i];
        i++;
    }
    //get index of to
    int idxto = line.find("to");
    i = idxto + 3;
    while (i < line.size())
    {
        tostr += line[i];
        i++;
    }

    from = stoi(fromstr);
    to = stoi(tostr);
    move = stoi(movestr);

    return make_tuple(from, to, move);
}

string part2(vector<string> lines, vector<stack<char>> stacks) {
    string ret = "";
    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        tuple<int, int, int> pos = get_move_from_to(line);
        int from = get<0>(pos) - 1; //stacks are 0 indexed
        int to = get<1>(pos) - 1; //stacks are 0 indexed
        int move = get<2>(pos);

        //I want to move the items and them to stay in the same order
        // i will need to have a temporary stack to reverse it afterwards
        stack<char> temp;
        for (int j = 0; j < move; j++)
        {
            char c = stacks[from].top();
            stacks[from].pop();
            temp.push(c);
        }
        for (int j = 0; j < move; j++)
        {
            char c = temp.top();
            temp.pop();
            stacks[to].push(c);
        }
    }
    //take the first char from each stack
    for (int i = 0; i < stacks.size(); i++)
    {
        ret += stacks[i].top();
    } 
    return ret;   
}