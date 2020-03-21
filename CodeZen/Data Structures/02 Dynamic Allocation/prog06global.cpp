#include <iostream>
using namespace std;

// BAD PRACTICE TO DECLARE GLOBAL VARIABLES
int a;

void g()
{
    a++;
    cout << " in function g " << a << endl;
}
void f()
{
    cout << " in function f " << a << endl;
    a++;
    g();
}
int main()
{
    a = 10;
    f();
    f();
    cout << " in function main " << a << endl;
}