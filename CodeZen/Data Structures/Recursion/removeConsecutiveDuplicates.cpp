#include <iostream>
using namespace std;
// #include "solution.h"

void removeConsecutiveDuplicates(char *input)
{
    int i;
    if (input[0] == '\0')
    {
        // cout << "debug 1 " << endl;
        return;
    }

    else
    {
        if (input[0] != input[1])
        {
            // cout << "debug 2 " << endl;
            removeConsecutiveDuplicates(input + 1);
        }
        else if (input[0] == input[1])
        {
            // cout << "debug 3 " << endl;
            for (i = 0; input[i] != '\0'; i++)
                input[i] = input[i + 1];
            input[i] = '\0';
            removeConsecutiveDuplicates(input);
        }
    }
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}