#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);

    int n, d;
    cin >> n >> d;

    int div = n / d;
    int rem = n % d;

    if (rem == 0)
        cout << div << endl;
    else
        cout << div << " " << rem << "/" << d << endl;

    return 0;
}
// // Sample IO
// 22 6
// 3 4/6
