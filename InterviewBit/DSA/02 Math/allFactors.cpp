// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> allFactors(int A)
{

    vector<int> result;
    deque<int> reverseResult;
    for (int i = 1; i * i <= A; i++)
    {
        if (A % i == 0)
        {
            if (i * i != A)
            {
                result.push_back(i);
                reverseResult.push_back(A / i);
            }
            else
                result.push_back(i);
        }
    }
    while (!reverseResult.empty())
    {
        auto ele = reverseResult.back();
        reverseResult.pop_back();
        result.push_back(ele);
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        cin >> n;
        auto result = allFactors(n);
        for (auto ele : result)
            cout << ele << " ";
        cout << endl;
    }
}
