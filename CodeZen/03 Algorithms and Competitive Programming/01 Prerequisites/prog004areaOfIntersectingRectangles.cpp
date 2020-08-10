#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int A1 = (x2 - x1) * (y2 - y1);
    int A2 = (x4 - x3) * (y4 - y3);

    int leftIntersection = max(x1, x3);
    int rightIntersection = min(x2, x4);

    int bottomIntersection = max(y1, y3);
    int topIntersection = min(y2, y4);

    int Aintr = 0;
    if ((leftIntersection < rightIntersection) && (bottomIntersection < topIntersection))
        Aintr = (rightIntersection - leftIntersection) * (topIntersection - bottomIntersection);
    int ans = A1 + A2 - Aintr;
    cout << ans << endl;

    return 0;
}
// // Sample IO
// 1 1 3 4
// 2 3 6 7

// 21