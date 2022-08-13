// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#include <cmath>

class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int distance(Point A, Point B)
{
    // float distance = pow(pow(A.x - B.x, 2) + pow(A.y - B.y, 2), 0.5);
    float distance = max(abs(A.x - B.x), abs(A.y - B.y));
    return (int)distance;
}

int coverPoints(vector<int> &A, vector<int> &B)
{
    // int size = (A.size() <= B.size())? A.size() : B.size();
    int totalDistance = 0;

    // for (auto &ele : A)
    //     cout << ele << " ";

    for (int i = 1; i < A.size(); i++)
    {
        Point a(A[i - 1], B[i - 1]);
        Point b(A[i], B[i]);

        int temp = distance(a, b);
        // cout << i << temp << endl;
        totalDistance += temp;
    }

    return totalDistance;
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
        int size;
        cin >> size;
        vector<int> A(size);
        vector<int> B(size);
        for (int i = 0; i < size; i++)
            cin >> A[i];

        for (int i = 0; i < size; i++)
            cin >> B[i];

        cout << coverPoints(A, B) << endl;
    }
}

// // Sample IO
// 2

// 3
// 0 1 1
// 0 1 2

// 2
// -7 -13
// 1 -5

// // output
// 2
// 6
