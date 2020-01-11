#include <iostream>
#include <string.h>
// #include "solution.h"
using namespace std;

int getCodes(string input, string output[10000])
{
    if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    int k = 0;
    char start = 'a' + input[0] - '0' - 1;
    string *newOutput = new string[10000];
    int smallSize = getCodes(input.substr(1), newOutput);
    for (int i = 0; i < smallSize; i++)
    {
        output[k++] = start + newOutput[i];
    }

    string *mGetOutput = new string[10000];
    int mGet = 0;
    if (input.length() >= 2)
    {
        string mLeft = input.substr(0, 2);
        string rLeft = input.substr(2);
        int number = stoi(mLeft);
        if (number > 10 && number <= 26)
        {
            mGet = getCodes(rLeft, mGetOutput);
            for (int j = 0; j < mGet; j++)
            {
                char s1 = 'a' + ((number - 1));
                output[k++] = s1 + mGetOutput[j];
            }
        }
    }
    return k;
}
// char getMappedChar(char myChar)
// {
//     char i = myChar - '0';
//     return 'a' - i - 1;
// }
// int getCodes(string input, string output[10000])
// {
//     if (input.empty())
//     {
//         output[0] = "";
//         return 1;
//     }
//     string smallString = input.substr(1);
//     int *temp = new int[5000];
//     int smallOutputSize = getCodes(smallString, temp);
//     int currentCount = 0;
//     for (int i = 0; i < smallOutputSize; i++)
//         output[i + smallOutputSize] = getMappedChar(input[0]) + output[i];
// }

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
