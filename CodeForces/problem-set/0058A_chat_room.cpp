// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool isValid(string temp)
{
    string pattern = "hello";

    int k = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == pattern[k])
            k++;
    }

    if (k != pattern.length())
        return false;
    else
        return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    string temp;
    cin >> temp;

    if (isValid(temp))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
