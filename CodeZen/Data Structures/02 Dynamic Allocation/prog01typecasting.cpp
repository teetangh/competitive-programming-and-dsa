#include <iostream>
using namespace std;

int main()
{
    int i = 65;
    char c = i;
    cout << c << endl;

    int *p = &i;
    char *pc = (char *)p;

    cout << endl;
    cout << p << endl;
    cout << pc << endl;
    cout << *p << endl;
    cout << *pc << endl;
    cout << endl;

    cout << *(pc) << endl;
    //NULL OUTPUT
    // cout << *(pc + 1) << endl;
    // cout << *(pc + 2) << endl;
    // cout << *(pc + 3) << endl;
}