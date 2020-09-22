#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

void printCurrentString(string input, char result[], int count[], int level)
{
    if (level == input.size())
    {
        cout << result << endl;
        return;
    }
    else
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (count[i] == 0)
                continue;
            else
            {
                result[level] = input[i];
                count[i]--;
                printCurrentString(input, result, count, level + 1);
                count[i]++;
            }
        }
    }
}

void printPermutations(string input)
{
    // cout << input.size() << endl;
    char *result = new char[input.size() + 1];
    result[input.size()] = '\0';
    int *count = new int[input.size()];
    for (int i = 0; i < input.size(); i++)
        count[i] = 1;
    printCurrentString(input, result, count, 0);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
