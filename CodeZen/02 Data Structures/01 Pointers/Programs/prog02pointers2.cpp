#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    int *q = p;

    cout << sizeof(p) << endl;
    cout << i << endl;
    cout << *p << endl;
    i++;
    cout << i << endl;
    cout << *p << endl;

    int a = i;
    a++;
    cout << a << endl;
    cout << *p << endl;

    i = 12;
    cout << i << endl;
    cout << *p << endl;
    *p = 23;
    cout << i << endl;
    cout << *p << endl;

    (*p)++;
    cout << i << endl;
    cout << *p << endl;
    cout << *q << endl;
    
}
// // Output
// 8
// 10
// 10
// 11
// 11
// 12
// 11
// 12
// 12
// 23
// 23
// 24
// 24
// 2