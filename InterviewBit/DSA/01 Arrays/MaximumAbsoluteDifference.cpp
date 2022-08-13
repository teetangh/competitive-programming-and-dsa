// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// int custom(vector<int> &A , int i , int j)
// {
//     return abs(A[i] - A[j]) + abs(i - j);
// }

// int maxArr(vector<int> &A)
// {
//     int maxAbsDiff = INT_MIN;
//     for(int i = 0 ; i < A.size() - 1; i++)
//     {
//         for(int j = i + 1 ; j < A.size() ; j++)
//         {
//             maxAbsDiff = max(maxAbsDiff , custom(A,i,j));
//         }
//     }

//     return maxAbsDiff;
// }

int maxArr(vector<int> &A)
{
    vector<int> temp1(A.size());
    vector<int> temp2(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        temp1[i] = (A[i] + i);
        temp2[i] = (A[i] - i);
    }

    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int diff1 = 0;
    for (auto ele : temp1)
    {
        max1 = max(max1, ele);
        min1 = min(min1, ele);
    }
    diff1 = max1 - min1;

    int max2 = INT_MIN;
    int min2 = INT_MAX;
    int diff2 = 0;
    for (auto ele : temp2)
    {
        max2 = max(max2, ele);
        min2 = min(min2, ele);
    }
    diff2 = max2 - min2;

    return max(diff1, diff2);
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
        cout << maxArr(A) << endl;
    }
}
