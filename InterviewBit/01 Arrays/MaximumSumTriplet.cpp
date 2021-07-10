// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long int lli;

// int solve(vector<int> &A)
// {

//     set<int> left, right;

//     left.insert(A[0]);
//     for (int i = 2; i < A.size(); i++)
//         right.insert(A[i]);

//     int maxSum = INT_MIN;

//     for (int i = 1; i < A.size() - 1; i++)
//     {
//         int currentSum = 0;

//         currentSum += A[i];

//         // right side
//         bool added = false;
//         for (auto rit = right.rbegin(); rit != right.rend(); rit++)
//         {
//             if (*rit > A[i])
//             {
//                 currentSum += *rit;
//                 added = true;
//                 break;
//             }
//         }
//         if (!added)
//             currentSum = INT_MIN;

//         // left Side
//         added = false;
//         for (auto it = left.begin(); it != left.end(); it++)
//         {
//             if (*it > A[i])
//             {
//                 currentSum += *it;
//                 added = true;
//                 break;
//             }
//         }
//         if (!added)
//             currentSum = INT_MIN;

//         if (currentSum > maxSum)
//             maxSum = currentSum;

//         left.insert(A[i]);
//         auto it = right.find(A[i + 1]);
//         right.erase(it);
//     }

//     return maxSum;
// }

int solve(vector<int> &A)
{
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int j = 1; j < A.size() - 1; j++)
    {
        currentSum = A[j];

        bool added = false;
        int maxLeft = INT_MIN;
        for (int k = j + 1; k < A.size(); k++)
        {
            if (A[j] <= A[k])
            {
                added = true;
                maxLeft = max(A[k], maxLeft);
            }
        }
        if (!added)
            currentSum = INT_MIN;
        else
            currentSum += maxLeft;

        added = false;
        int maxRight = INT_MIN;
        for (int i = 0; i < j; i++)
        {
            if (A[i] <= A[j])
            {
                added = true;
                maxRight = max(A[i], maxRight);
            }
        }
        if (!added)
            currentSum = INT_MIN;
        else
            currentSum += maxRight;

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
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

        cout << solve(A) << endl;
    }
}
