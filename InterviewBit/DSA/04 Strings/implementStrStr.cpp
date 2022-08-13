// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int strStr(const string haystack, const string needle)
{

    if (needle.empty())
        return -1;

    if (needle.size() > haystack.size())
        return -1;

    for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
    {
        int found = i;
        for (int j = 0; j < needle.size(); j++)
        {
            if (haystack[i + j] != needle[j])
            {
                found = -1;
                break;
            }
        }

        if (found != -1)
            return found;
    }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        string haystack;
        string needle;

        cin >> haystack >> needle;
        cout << strStr(haystack, needle) << endl;
    }

    return 0;
}
