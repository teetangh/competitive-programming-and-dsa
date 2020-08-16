#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

char nonRepeatingCharacter(string str)
{
    map<char, char> frequency;
    for (int i = 0; i < str.length(); i++)
    {
        char currentChar = str[i];
        frequency[currentChar]++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (frequency[str[i]] == 1)
            return str[i];
    }

    return str[0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;
        cout << nonRepeatingCharacter(s) << endl;
    }

    return 0;
}
// // Sample IO
// 2
// aabbc
// abc

// c
// a
