#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

char getChar(int i)
{
    return (char)(i + 97);
}

void printPalindromicString(string s)
{
    map<char, vector<int>> indexesMap;

    // Storing the characters and their frequencies in a map
    for (int i = 0; i < s.length(); i++)
        indexesMap[s[i]].push_back(i);

    int odd_frequency_count = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((indexesMap[getChar(i)].size() % 2) != 0)
        {
            odd_frequency_count++;
        }
    }
    // Only allowed to have a single odd frequency element in the string/map
    if (odd_frequency_count >= 2)
    {
        cout << "-1" << endl;
        return;
    }

    // Creating an output string of same length as input string
    int ans[s.length()];

    // Initializing pointers to beginning and ending of the string
    int start = 0;
    int end = s.length() - 1;

    for (int i = 0; i < 26; i++)
    {
        char currentChar = getChar(i); // To prevent excessive function calls
        for (int j = 0; j < indexesMap[currentChar].size(); j += 2)
        {
            // For the odd frequency element
            if ((indexesMap[currentChar].size() - j) == 1)
            {
                ans[s.length() / 2] = indexesMap[currentChar][j];
                continue;
            }
            // inserting the palindromically
            ans[start] = indexesMap[currentChar][j];
            ans[end] = indexesMap[currentChar][j + 1];

            // Incrementing and decrementing the pointers
            start++;
            end--;
        }
    }

    // Printing the indexes of the letters for the new output string
    for (int i = 0; i < s.length(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return;
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
        printPalindromicString(s);
    }
    return 0;
}
