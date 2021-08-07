// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// int bitsDifference(int x, int y)
// {
//     auto result = x ^ y;
//     int count = 0;
//     const int MOD = 1000000007;

//     while (result != 0)
//     {
//         if (result & 1)
//             count = (count + 1) % MOD;
//         result >>= 1;
//     }
//     return count % MOD;
// }

// int hammingDistance(const vector<int> &A)
// {
//     const int MOD = 1000000007;
//     int answer = 0;

//     for (int i = 0; i < A.size() - 1; i++)
//     {
//         for (int j = i + 1; j < A.size(); j++)
//         {
//             answer += bitsDifference(A[i], A[j]) % MOD;
//         }
//     }
//     return (answer % MOD) * 2;
// }
int hammingDistance(const vector<int> &A)
{
    const int MOD = 1000000007;
    int answer = 0;

    int n = A.size();
    int x = 0;
    int y = 0;
    for (int i = 0; i < 32; i++)
    {
        x = 0, y = 0;
        for (int j = 0; j < n; j++)
            if (A[j] & (1 << i))
                x++;
        y = (n - x);

        answer += ((2 * ((x % MOD) * (y % MOD)) % MOD) % MOD) % MOD;
    }

    return answer % MOD;
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
        cout << hammingDistance(A) << endl;
    }
}
