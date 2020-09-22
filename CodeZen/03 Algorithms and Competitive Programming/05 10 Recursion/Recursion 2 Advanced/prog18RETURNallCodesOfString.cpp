#include <iostream>
// #include "solution.h"
#include <string.h>
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
