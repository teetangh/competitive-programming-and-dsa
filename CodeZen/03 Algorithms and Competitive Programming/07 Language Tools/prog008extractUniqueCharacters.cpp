#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

#include <bits/stdc++.h>
string uniqueChar(char *str)
{
    map<char, int> mp;
    string final_string;
    for (int i = 0; str[i] != '\0'; i++)
    {
        mp[str[i]]++;
        if (mp[str[i]] <= 1)
            final_string.push_back(str[i]);
        else
            continue;
    }
    return final_string;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    char input[1000000];
    cin >> input;
    cout << uniqueChar(input) << endl;
}
