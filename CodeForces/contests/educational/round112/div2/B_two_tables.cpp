// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int adjustHorizontally(int W, int H,
                       int x1, int y1, int x2, int y2,
                       int w, int h)
{
    if (w > W || (y2 - y1) + h > H)
        return -1;

    if (H - y2 >= h || y1 >= h)
        return 0;

    return min(abs(y1 - h), abs((H - y2) - h));
}

int adjustVertically(int W, int H,
                     int x1, int y1, int x2, int y2,
                     int w, int h)
{
    if (h > H || (x2 - x1) + w > W)
        return -1;

    if (W - x2 >= w || x1 >= w)
        return 0;

    return min(abs(x1 - w), abs((W - x2) - w));
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
        int W, H;
        int x1, y1, x2, y2;
        int w, h;

        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;

        int horizontal = adjustHorizontally(W, H,
                                            x1, y1, x2, y2,
                                            w, h);

        int vertical = adjustVertically(W, H,
                                        x1, y1, x2, y2,
                                        w, h);

        if (horizontal == -1 && vertical == -1)
            cout << -1 << endl;
        else
        {
            if (horizontal == -1)
                cout << vertical << endl;
            else if (vertical == -1)
                cout << horizontal << endl;
            else
                cout << min(vertical, horizontal) << endl;
        }
    }
    return 0;
}
