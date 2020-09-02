#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int Nwindows;
    cin >> Nwindows;
    vector<lli> windows(Nwindows);

    for (int i = 0; i < Nwindows; i++)
        cin >> windows[i];

    while (true)
    {
        bool flag = false;
        for (int i = 0; i < Nwindows; i++)
        {
            if (windows[i] < i + 1)
            {
                flag = true;
                cout << i + 1 << endl;
            }
            if (flag == true)
                break;
        }

        if (flag == true)
            break;

        for (int i = 0; i < Nwindows; i++)
            windows[i] -= Nwindows;
    }

    return 0;
}
