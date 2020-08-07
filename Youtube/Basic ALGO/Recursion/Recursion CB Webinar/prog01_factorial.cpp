#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;

    int smallFact = fact(n - 1);
    int ans = smallFact * n;
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ans = fact(n);
    cout << ans;
    return 0;
}
