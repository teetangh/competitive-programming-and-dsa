#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int first, second;
        cin >> first >> second;
        cout << (first + second) % 12 << endl;
    }

    return 0;
}
