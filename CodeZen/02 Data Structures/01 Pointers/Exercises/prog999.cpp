#include <iostream>
using namespace std;
int f(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;

    cout << "x is" << x << endl;
    cout << "y is" << y << endl;
    cout << "z is" << z << endl;
    cout << "py is" << py << endl;
    cout << "ppz is" << ppz << endl;
    cout << "*py is" << *py << endl;
    cout << "**ppz is" << **ppz << endl;

    return x + y + z;
}
int main()
{
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}