#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    cout << &i << endl;

    int *p = &i;
    cout << p << endl;

    cout << *p << endl;

    float f = 10.2;
    float *pf = &f;
    cout << pf << endl;

    double d = 122.32;
    double *df = &d;
    cout << df << endl;
}
// Output
// 0x7ffc942ce010
// 0x7ffc942ce010
// 10
// 0x7ffc942ce014
// 0x7ffc942ce018