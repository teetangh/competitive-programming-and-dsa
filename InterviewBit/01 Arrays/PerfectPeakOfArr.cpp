// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int perfectPeak(vector<int> &A)
{

    multiset<int> leftSide;
    multiset<int> rightSide;

    leftSide.insert(A[0]);
    rightSide.insert(A[A.size() - 1]);

    for (int i = 2; i < A.size(); i++)
        rightSide.insert(A[i]);

    for (int i = 1; i < A.size() - 1; i++)
    {
        bool valid = true;

        auto it1 = leftSide.rbegin();
        if (*it1 >= A[i])
            valid = false;

        auto it2 = rightSide.begin();
        if (A[i] >= *it2)
            valid = false;

        if (!valid)
        {
            leftSide.insert(A[i]);
            rightSide.erase(rightSide.lower_bound(A[i + 1]));
            continue;
        }
        return 1;
    }

    return 0;
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
        int size;
        cin >> size;
        vector<int> A(size);
        for (int i = 0; i < size; i++)
            cin >> A[i];

        cout << perfectPeak(A) << endl;
    }
}

// // Sample IO
// 1
// 9
// 5 1 4 3 6 8 10 7 9

// 1