// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

string minWindow(string s, string t)
{
    map<char, int> mp;
    for (auto elem : t)
        mp[elem]++;

    int lenT = t.size(), st = 0, en = 0, len = INT_MAX, begin = 0;
    while (en < s.size())
    {
        if (mp[s[en++]]-- > 0)
            lenT--;
        while (lenT == 0)
        {
            if (en - st < len)
                len = en - (begin = st);
            if (mp[s[st++]]++ == 0)
                lenT++;
        }
    }
    return len == INT_MAX ? "" : s.substr(begin, len);
}
int main()
{

    fastio();

    string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    cin >> s;
    cout << minWindow(s, t) << endl;

    return 0;
}
