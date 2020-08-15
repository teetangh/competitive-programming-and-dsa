#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int sum(int *a, int size)
{
    cout << "In Sum Function " << sizeof(a) << endl;

    int ans = 0;
    for (int i = 0; i < size; i++)
        ans += a[i];

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int a[10];
    cout << "In Main " << sizeof(a) << endl;

    cout << "Value of Sum " << sum(a, 7) << endl;
}
