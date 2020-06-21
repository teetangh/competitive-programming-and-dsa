#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    // tertiary operator
    return (a < b) ? a : b;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;

    // int c;
    // if (a > b)
    //     c = a;
    // else
    //     c = b;

    int c = max(a, b);
    cout << " c is " << c << endl;

    int x, y;
    x = 12;
    y = 34;
    int z = max(x, y);
    cout << " z is " << z << endl;

    return 0;
}
