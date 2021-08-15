// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl

int woodCut(vector<int> &A, int mid)
{
    int sum = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        auto curr = A[i] - mid;
        if (curr > 0)
            sum += (curr);
        else
            break;
    }

    return sum;
}

int solve(vector<int> &A, int B)
{

    sort(A.begin(), A.end());

    int low = 0;
    int high = A[A.size() - 1];
    int cut, mid;
    int res;

    while (low <= high)
    {

        mid = low + (high - low) / 2;
        cut = woodCut(A, mid);

        // watch2(low, high);
        // watch2(mid, cut);

        if (cut == B)
            return mid;
        else if (cut < B)
            high = mid - 1;
        else if (cut > B)
        {
            res = mid;
            low = mid + 1;
        }
    }

    return res;
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
