// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int leftBinarySearch(vector<int> &A, int B, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int rightBinarySearch(vector<int> &A, int B, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
int solve(vector<int> &A, int B)
{

    if (A[0] == B)
        return 0;
    else if (A[A.size() - 1] == B)
        return A.size() - 1;

    int low = 0;
    int high = A.size() - 1;
    int mid;

    int bitonicMax = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
        {
            bitonicMax = mid;
            break;
        }
        else if (A[mid - 1] >= A[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (bitonicMax != -1 && A[bitonicMax] == B)
        return bitonicMax;

    int leftSide = leftBinarySearch(A, B, 0, bitonicMax);
    int rightSide = rightBinarySearch(A, B, bitonicMax, A.size() - 1);

    if (leftSide == -1 && rightSide == -1)
        return -1;
    else if (leftSide == -1)
        return rightSide;
    else
        return leftSide;
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

    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int B;
        cin >> B;
        cout << solve(A, B) << endl;
    }
}
