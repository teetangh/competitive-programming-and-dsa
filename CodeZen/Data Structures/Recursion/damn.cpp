#include <bits/stdc++.h>
using namespace std;
#define mamba()                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
typedef long long int ll;
int main()
{
    ll n, x = 0, a = 1, b, c = 1;
    cin >> n;
    bool bo = false;
    while (n > 0)
    {
        a = n % 10;
        if (a == 0 && bo == false)
        {
            n /= 10;
            continue;
        }
        b = (b * x) + a;
        x = 10;
        bo = true;
        n /= 10;
    }
    cout << b;
}