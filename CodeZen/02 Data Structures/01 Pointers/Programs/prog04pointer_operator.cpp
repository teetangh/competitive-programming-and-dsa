#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;

    cout << p << endl;
    p = p + 1;
    cout << p << endl;
    p = p + 2;
    cout << p << endl;
    p = p - 2;
    cout << p << endl;
    p++;
    cout << p << endl;
    p--;
    cout << p << endl;

    double d = 102;
    double *dp = &d;
    cout << dp << endl;
    dp++;
    cout << dp;
}
// // Output
// 0x7ffca21eff9c
// 0x7ffca21effa0
// 0x7ffca21effa8
// 0x7ffca21effa0
// 0x7ffca21effa4
// 0x7ffca21effa0
// 0x7ffca21effa0