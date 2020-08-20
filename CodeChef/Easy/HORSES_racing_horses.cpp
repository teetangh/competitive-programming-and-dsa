#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    int num_of_horses;
    while (test_cases--)
    {
        cin >> num_of_horses;
        vector<int> horse_skill(num_of_horses);
        for (int i = 0; i < num_of_horses; i++)
            cin >> horse_skill[i];

        sort(horse_skill.begin(), horse_skill.end());

        int i, j;
        int min_diff = INT_MAX;
        for (i = 0, j = 1; i < num_of_horses - 1 && j < num_of_horses; i++, j++)
        {
            if ((horse_skill[j] - horse_skill[i]) <= min_diff)
                min_diff = (horse_skill[j] - horse_skill[i]);
        }
        cout << min_diff << endl;
        horse_skill.clear();
    }

    return 0;
}
// Example:
// Input:
// 1
// 5
// 4 9 1 32 13

// Output:
// 3
