#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli calculate_k(lli balls, lli k)
{
    lli sharma = 0;
    lli singh = 0;

    lli count = 0;

    lli intial_balls = balls;

    while (balls)
    {
        sharma += k, balls -= k, count++;
        if (sharma >= initial_balls / 2)
            return count;

        singh += balls / 10, balls /= 10, count++;
        if (sharma >= initial_balls / 2)
            return count;
    }
    return -1;
}

lli minimum_k(lli left, lli right)
{
    lli min_k = INT_MAX;

    while (left < right)
    {
        lli mid = (left + right) / 2;
        if (left == right)
            return calculate_k(balls, mid);
        else if (calculate_k(balls, mid) > min_k)
    }
}

int main()
{

    lli balls;
    cin >> balls;

    return 0;
}
