// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool isSameAfterRotation(string temp, int bitsRotated)
{
    if (temp.size() == 0 || temp.size() == 1)
        return true;
    string part1, part2;
    for (int i = bitsRotated; i < temp.size(); i++)
        part1 += temp[i];
    for (int i = 0; i < bitsRotated; i++)
        part2 += temp[i];

    string newString = part1 + part2;

    for (int i = 0; i < temp.size(); i++)
        if (newString[i] != temp[i])
            return false;

    return true;
}

int rotationTime(string temp)
{
    long long int timer = 1;
    int bitsRotated = 0;

    const int MOD = 1e9 + 7;
    while (true)
    {
        bitsRotated = (timer * (timer + 1) / 2);
        bitsRotated = bitsRotated % temp.size();
        if (isSameAfterRotation(temp, bitsRotated))
            break;
        timer++;
    }

    return (int)(timer % MOD);
}

long long int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long int lcm(vector<int> rotationTimes)
{
    long long int ans = rotationTimes[0];

    for (int i = 1; i < rotationTimes.size(); i++)
        ans = ((ans * rotationTimes[i]) / (gcd(rotationTimes[i], ans)));

    return ans;
}

int solve(vector<string> &A)
{
    vector<int> rotationTimes(A.size());
    const int MOD = 1e9 + 7;
    for (int i = 0; i < A.size(); i++)
        rotationTimes[i] = rotationTime(A[i]);

    long long int ans = lcm(rotationTimes);
    return (int)(ans % MOD);
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
        int n;
        cin >> n;

        vector<string> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << solve(A) << endl;
    }
}
