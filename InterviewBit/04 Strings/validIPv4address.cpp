// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool validSection(string n)
{
    if (n.size() >= 2 && n[0] == '0')
        return false;

    int value = 0;
    for (int i = 0; i < n.size(); i++)
    {
        value = value * 10 + (n[i] - '0');
        if (value < 0 || value > 255)
            return false;
    }

    return true;
}

vector<string> restoreIpAddresses(string nums)
{

    if (nums.size() < 4 || nums.size() > 12 || nums.empty())
        return {};

    string quad1, quad2, quad3, quad4;
    string result;
    vector<string> answer;
    for (int i = 1; i <= 3; i++)
    {
        quad1 += nums[i - 1];
        if (quad1.size() >= nums.size() || !validSection(quad1))
            continue;

        quad2.clear();
        for (int j = 1; j <= 3; j++)
        {
            quad2 += nums[i + j - 1];

            if (quad1.size() + quad2.size() >= nums.size() || !validSection(quad2))
                continue;

            quad3.clear();
            for (int k = 1; k <= 3; k++)
            {
                quad3 += nums[i + j + k - 1];

                if (quad1.size() + quad2.size() + quad3.size() >= nums.size() || !validSection(quad3))
                    continue;

                quad4.clear();
                for (int l = 1; l <= 3; l++)
                {
                    quad4 += nums[i + j + k + l - 1];
                    if (quad1.size() + quad2.size() + quad3.size() + quad4.size() != nums.size() || !validSection(quad4))
                        continue;

                    result = quad1 + '.' + quad2 + '.' + quad3 + '.' + quad4;
                    answer.push_back(result);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
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
        string A;
        cin >> A;

        auto result = restoreIpAddresses(A);
        for (auto ele : result)
            cout << ele << endl;
        cout << "\n==================\n";
    }
}
