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


// Sample IO
// 8

// 0
// 0000
// 0100100
// 25525511
// 255255111
// 25525511135
// 01111
// 12345678



// ==================
// 0.0.0.0

// ==================
// 0.10.0.100
// 0.100.10.0

// ==================
// 2.55.255.11
// 25.5.255.11
// 25.52.55.11
// 255.2.55.11
// 255.25.5.11
// 255.25.51.1
// 255.255.1.1

// ==================
// 2.55.255.111
// 25.5.255.111
// 25.52.55.111
// 255.2.55.111
// 255.25.5.111
// 255.25.51.11
// 255.255.1.11
// 255.255.11.1

// ==================
// 255.255.11.135
// 255.255.111.35

// ==================
// 0.1.1.11
// 0.1.11.1
// 0.11.1.1

// ==================
// 1.234.56.78
// 12.34.56.78
// 123.4.56.78
// 123.45.6.78
// 123.45.67.8

// ==================
