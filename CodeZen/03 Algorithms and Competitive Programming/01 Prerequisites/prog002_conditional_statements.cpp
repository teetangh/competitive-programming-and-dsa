#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);

    int r, s;
    cin >> r >> s;

    int nos = r * s;
    int tickets;
    cin >> tickets;
    if (nos >= tickets)
        cout << tickets << " " << 0 << endl;
    else
        cout << nos << " " << (tickets - nos) << endl;
    return 0;
}

// // Sample IO
// 12 7
// 100

// 84 16
