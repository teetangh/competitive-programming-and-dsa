#include <bits/stdc++.h>
using namespace std;

void display_rankings(map<int, vector<string>> mp)
{
    int ranking = 1;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        for (auto &ele : it->second)
            cout << ranking++ << " " << ele << endl;
    }
}
int main()
{
    int test_cases;
    cin >> test_cases;

    map<int, vector<string>> mp;

    while (test_cases--)
    {
        int m1, m2, m3;
        string temp;

        cin >> temp >> m1 >> m2 >> m3;
        int total = m1 + m2 + m3;

        mp[total].push_back(temp);
    }

    display_rankings(mp);

    return 0;
}
// Sample Input:
// 3
// Mohit 94 85 97
// Shubham 93 91 94
// Rishabh 95 81 99

// Sample Output:
// 1 Shubham
// 2 Mohit
// 3 Rishabh