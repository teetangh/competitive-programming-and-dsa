#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << a << endl;
    // Char Pointer print till end
    cout << b << endl;

    // Char Pointer still print till end
    char *c = &b[0];
    cout << c << endl;

    // Garbage Output
    char c1 = 'a';
    char *pc = &c1;
    cout << c1 << endl;
    cout << pc << endl;

    char str[] = "abcde";
    char *pstr = "abcde";

    return 0;
}
