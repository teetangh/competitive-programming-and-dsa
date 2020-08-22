#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> mp;
    string str;

    int length;
    cin >> length;
    cin >> str;
    for (int i = 0; i < length; i++)
        mp[str[i]]++;

    cout << mp['a'] << " " << mp['s'] << " " << mp['p'] << endl;

    // for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    // {
    //     cout << itr->first
    //          << '\t' << itr->second << '\n';
    // }

    return 0;
}
