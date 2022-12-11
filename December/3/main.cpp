#include <iostream>
#include <string>   
#include <vector>
#include <fstream>  

using namespace std;

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

    int sum = 0;
    //print out the vector
    for (int i = 0; i < lines.size(); i++)
    {
        //divide the string into two parts depending on the length
        int length = lines[i].length();
        int half = length / 2;
        string first = lines[i].substr(0, half);
        string second = lines[i].substr(half, length);

        //find the common char in the two strings
        char common = ' ';
        for (int j = 0; j < first.length(); j++)
        {
            for (int k = 0; k < second.length(); k++)
            {
                if (first[j] == second[k])
                {
                    common = first[j];
                    break;
                }
            }
        }

        //convert char to int, a = 0, b = 1, etc. A = 26, B = 27, etc.
        int commonInt = 0;
        if (common >= 'a' && common <= 'z')
        {
            commonInt = common - 'a' + 1;
        }
        else if (common >= 'A' && common <= 'Z')
        {
            commonInt = common - 'A' + 26 + 1;
        }

        //add the common int to the sum
        sum += commonInt;
    }

    cout << sum << endl;
    return 0;
}