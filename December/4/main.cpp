//generic main
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

int part1(vector<string> lines);
int part2(vector<string> lines);

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

    int ret = part1(lines);
    cout << "Part 1: " << ret << endl;

    ret = part2(lines);
    cout << "Part 2: " << ret << endl;
    return 0;
}

//part 1
int part1(vector<string> lines) {
    int countContains = 0;

    while (lines.size() > 0) {
        //get the first line
        string l = lines[0];

        //remove the first line
        lines.erase(lines.begin());

        vector<string> substrings;
        size_t pos = 0;
        std::string token;
        while ((pos = l.find(",")) != std::string::npos) {
            token = l.substr(0, pos);
            substrings.push_back(token);
            l.erase(0, pos + 1);
        }
        substrings.push_back(l);

        int a_sup = 0;
        int b_sup = 0;
        int a_inf = 0;
        int b_inf = 0;

        for (int j = 0; j < substrings.size(); j+=2) {
            //the 1st substring is of the form "A_inf-A_Sup"
            //the 2nd substring is of the form "B_inf-B_Sup"

            //get the 1st substring
            string s = substrings[j];

            //find the index of the '-'
            int index = s.find("-");
            //get the 1st number
            string a_inf_str = s.substr(0, index);
            //get the 2nd number
            string a_sup_str = s.substr(index + 1, s.length());

            //convert the strings to ints
            a_inf = stoi(a_inf_str);
            a_sup = stoi(a_sup_str);

            //get the 2nd substring
            s = substrings[j + 1];

            //find the index of the '-'
            index = s.find("-");
            //get the 1st number
            string b_inf_str = s.substr(0, index);
            //get the 2nd number
            string b_sup_str = s.substr(index + 1, s.length());

            //convert the strings to ints
            b_inf = stoi(b_inf_str);
            b_sup = stoi(b_sup_str);

            //check if the 2nd substring is contained in the 1st substring or vice versa
            if ((a_inf <= b_inf && b_sup <= a_sup) || (b_inf <= a_inf && a_sup <= b_sup)) {
                countContains++;
            }
        }
    }
    return countContains;
}

//part 2
int part2(vector<string> lines) {
    int countContains = 0;

    while (lines.size() > 0) {
        //get the first line
        string l = lines[0];

        //remove the first line
        lines.erase(lines.begin());

        vector<string> substrings;
        size_t pos = 0;
        std::string token;
        while ((pos = l.find(",")) != std::string::npos) {
            token = l.substr(0, pos);
            substrings.push_back(token);
            l.erase(0, pos + 1);
        }
        substrings.push_back(l);

        int a_sup = 0;
        int b_sup = 0;
        int a_inf = 0;
        int b_inf = 0;

        for (int j = 0; j < substrings.size(); j+=2) {
            //the 1st substring is of the form "A_inf-A_Sup"
            //the 2nd substring is of the form "B_inf-B_Sup"

            //get the 1st substring
            string s = substrings[j];

            //find the index of the '-'
            int index = s.find("-");
            //get the 1st number
            string a_inf_str = s.substr(0, index);
            //get the 2nd number
            string a_sup_str = s.substr(index + 1, s.length());

            //convert the strings to ints
            a_inf = stoi(a_inf_str);
            a_sup = stoi(a_sup_str);

            //get the 2nd substring
            s = substrings[j + 1];

            //find the index of the '-'
            index = s.find("-");
            //get the 1st number
            string b_inf_str = s.substr(0, index);
            //get the 2nd number
            string b_sup_str = s.substr(index + 1, s.length());

            //convert the strings to ints
            b_inf = stoi(b_inf_str);
            b_sup = stoi(b_sup_str);

            //check if the 2nd substring overlaps with the 1st substring or vice versa
            if ((a_inf <= b_inf && b_inf <= a_sup) || (b_inf <= a_inf && a_inf <= b_sup)) {
                countContains++;
            }
        }
    }
    return countContains;
}