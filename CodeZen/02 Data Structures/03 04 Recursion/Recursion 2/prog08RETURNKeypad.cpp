#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    int x = num / 10;
    int y = num % 10;
    int count = 0;
    string temp;
    // cout << " debug 1 " << endl;
    string *tempoutput = new string[10000];

    if (y == 0)
    {
        // cout << " debug 2 " << endl;
        output[0] = "";
        return 1;
    }
    else
    {
        // cout << " debug 3 " << endl;
        int smallOutputSize = keypad(x, output);
        count = 0;
        if (y == 2)
            temp = "abc";
        else if (y == 3)
            temp = "def";
        else if (y == 4)
            temp = "ghi";
        else if (y == 5)
            temp = "jkl";
        else if (y == 6)
            temp = "mno";
        else if (y == 7)
            temp = "pqrs";
        else if (y == 8)
            temp = "tuv";
        else
            temp = "wxyz";

        for (int i = 0; i < smallOutputSize; i++)
        {
            // cout << " debug 3 " << endl;
            for (int j = 0; j < temp.size(); j++)
            {
                // cout << " debug 4 " << endl;
                tempoutput[(count++)] = output[i] + temp[j];
            }
        }

        for (int k = 0; k < count; k++)
            output[k] = tempoutput[k];

        return count;
    }
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
