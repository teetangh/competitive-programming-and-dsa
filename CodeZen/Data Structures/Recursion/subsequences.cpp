#include <iostream>
#include <cmath>
using namespace std;

int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = ' ';
        return 1;
    }
    else
    {
        string smallString = input.substr(1);
        int smallOutputSize = subs(smallString, output);
        for (int i = 0; i < smallOutputSize; i++)
            output[i + smallOutputSize] = input[0] + output[i];
        return 2 * smallOutputSize;
    }
}
int main()
{
    string input;
    getline(cin, input);

    string *output = new string[(int)pow(2, input.size())];
    int count = subs(input, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << endl;
}