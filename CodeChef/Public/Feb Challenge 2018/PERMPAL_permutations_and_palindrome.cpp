#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

list<int> permutation_palindrome(string s)
{
    map<char, vector<int>> mp;

    for (int i = 0; i < s.length(); i++)
        mp[s[i]].emplace_back(i);

    int odd_count = 0;
    int odd_character_index;
    for (auto &ele : mp)
    {
        if ((ele.second.size()) % 2 != 0)
        {
            odd_count++;
            odd_character_index = ele.second[0];
        }
    }

    if (odd_count > 1)
    {
        list<int> final_list = {-1};
        return final_list;
    }
    else
    {
        list<int> final_list;
        for (auto &ele : mp)
        {
            if (ele.second.size() % 2 == 0)
            {
                int i = 0;
                for (auto &vec : ele.second)
                {
                    if (i % 2 == 0)
                        final_list.push_front(vec);
                    else
                        final_list.push_back(vec);
                    i++;
                }
            }
        }
        final_list.insert(final_list.begin(), s.length() / 2, odd_character_index);
        return final_list;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;
        list<int> output = permutation_palindrome(s);
        for (auto &ele : output)
            cout << ele << " ";
        cout << endl;
        output.clear();
    }
}
// Input

// 4
// aa
// baa
// abc
// abab

// Output

// 1 2
// 2 1 3
// -1
// 1 2 4 3