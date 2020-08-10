#include <iostream>
using namespace std;

void increment(int &n)
{
    // Effectively (int& increment.n = main.n)
    n++;
}
// bad practice
int &f(int n)
{
    // Be carefeul when returning AS REFERENCE because
    // scope of local variables get deleted after function returns
    int a = n;
    return a;
}
// bad practice
int *f2()
{
    // Be carefeul when returning AS POINTER because
    // scope of local variables get deleted after function returns
    int i = 10;
    return &i;
}

int main(int argc, char const *argv[])
{
    int i = 10;
    int &j = i;

    // ERROR (Has to be done in the same line)
    // int &j;
    // j = i;

    increment(i);
    cout << "i is " << i << endl;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    // Catching by reference
    int &k = f(i);
    j = k;
    cout << " j is " << j << " k is " << k << endl;

    // Catching by pointer
    int *k2 = f2();
    return 0;
}
