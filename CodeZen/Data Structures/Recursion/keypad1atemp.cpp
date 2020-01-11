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
    int yt = y;
    while (yt >= 9)
        yt /= 10;

    if (x == 0)
    {
        cout << "debug 1" << endl;
        output[0] = "";
        return 1;
    }
    else
    {
        cout << "debug 2" << endl;
        int smallOutputSize = keypad(x, output);
        if (yt == 2)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('a' + i);
            return 3 * smallOutputSize;
        }
        else if (yt == 3)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('d' + i);
            return 3 * smallOutputSize;
        }
        else if (yt == 4)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('g' + i);
            return 3 * smallOutputSize;
        }
        else if (yt == 5)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('j' + i);
            return 3 * smallOutputSize;
        }
        else if (yt == 6)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('m' + i);
            return 3 * smallOutputSize;
        }
        else if (yt == 7)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('p' + i);
            return 4 * smallOutputSize;
        }
        else if (yt == 8)
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('t' + i);
            return 3 * smallOutputSize;
        }
        else
        {
            for (int i = 0; i < smallOutputSize; i++)
                output[i + smallOutputSize] = output[i] + (char)('w' + i);
            return 4 * smallOutputSize;
        }
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
