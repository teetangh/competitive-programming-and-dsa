#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    // Complete the code.
    int i;
    long int l;
    char c;
    float f;
    double d;

    cin >> i >> l >> c >> f >> d;

    printf("%d\n", i);
    printf("%ld\n", l);
    printf("%c\n", c);
    printf("%.3f\n", f);
    printf("%.9f\n", d);

    // cout << i << "\n";
    // cout << l << "\n";
    // cout << c << "\n";
    // cout << f << "\n";
    // cout << d << "\n";

    return 0;
}