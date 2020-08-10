#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    deque<int> dq;
    int n;
    while (test_cases--)
    {
        cin >> n;
        dq.push_back(n);
    }

    while (!dq.empty())
    {
        int current_sum = dq.front() + dq.back();
        cout << current_sum / 10 << " " << current_sum % 10 << " " << endl;
        dq.pop_back();
        dq.pop_front();
    }
    return 0;
}
// // Sample IO
// 10
// 26 96 18 24 87 51 44 86 75 32

// 5 8 
// 17 1 
// 10 4 
// 6 8 
// 13 8 
