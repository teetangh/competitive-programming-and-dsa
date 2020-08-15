#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int sum(int a[], int size, int si = 0)
{
    int ans = 0;
    for (int i = si; i < size; i++)
        ans += a[i];

    return ans;
}

int sum2(int a, int b, int c = 0, int d = 0)
{
    return (a + b + c + d);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int a[20];

    cout << sum(a, 20) << endl;
    cout << sum2(20, 30, 40) << endl;
    cout << sum2(20, 30, 40) << endl;
    cout << sum2(20, 30, 40, 50) << endl;
}
