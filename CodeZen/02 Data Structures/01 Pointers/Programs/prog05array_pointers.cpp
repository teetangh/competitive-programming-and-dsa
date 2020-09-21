#include <iostream>
using namespace std;

int main()
{
    int a[10];
    cout << a << endl;
    cout << &a << endl;

    a[0] = 5;
    a[1] = 10;
    cout << *a << endl;
    cout << *(a + 1) << endl;

    // a[i] = i[a] = *(a+i) = *(i+a)

    int b[10];
    // Same
    cout << b << endl;
    cout << &b << endl;
    // different
    int *q = b;
    cout << q << endl;
    cout << &q << endl;

    int *p = &a[0];
    cout << a << endl;
    cout << p << endl;

    cout << &a << endl;
    cout << &p << endl;

    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;

    p = p + 1;
    // a = a + 1;  // INVALID
    p = a + 1;  //VALID
}
// // Output
// 0x7ffe5336ea30
// 0x7ffe5336ea30
// 5
// 10
// 0x7ffe5336ea60
// 0x7ffe5336ea60
// 0x7ffe5336ea60
// 0x7ffe5336ea20
// 0x7ffe5336ea30
// 0x7ffe5336ea30
// 0x7ffe5336ea30
// 0x7ffe5336ea28
// 40
// 8
