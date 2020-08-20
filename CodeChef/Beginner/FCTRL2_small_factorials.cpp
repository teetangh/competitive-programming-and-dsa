#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;

ll factorial(ll num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    ll num;
    while (test_cases--)
    {
        cin >> num;
        cout << factorial(num) << endl;
    }
}
