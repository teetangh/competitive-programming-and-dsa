#include <iostream>
using namespace std;

int main()
{
    long num;
    cin >> num;

    long rem = 0;
    long revbin = 0;
    long b = 1;
    while (num != 0)
    {
        rem = num % 2;
        revbin = revbin + (rem * b);
        b = b * 10;
        num = num / 2;
    }
    cout << revbin;
}
