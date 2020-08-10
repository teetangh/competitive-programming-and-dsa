#include <iostream>
using namespace std;

void g(int const &a)
{
    // a++;
}

void f(const int *p)
{
    // (*p)++;
}

int main(int argc, const char **argv)
{
    int const i = 10;
    // int *p = &i;
    int const *p = &i;
    // (*p)++;

    int j = 12;
    int const *p2 = &j;
    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;

    int *p3 = &j;
    f(p3);
    g(j);

    return 0;
}