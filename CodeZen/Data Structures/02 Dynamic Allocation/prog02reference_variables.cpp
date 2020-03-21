#include <iostream>
using namespace std;

void increment(int &i)
{
    i++;
}

// Be carefeul when returning AS REFERENCE because
// scope of local variables get deleted after function returns
int &f(int n)
{
    int a = n;
    return a;
}

// Be carefeul when returning AS POINTER because
// scope of local variables get deleted after function returns
int *f2()
{
    int i = 10;
    return &i;
}

int main(int argc, char const *argv[])
{
    int i = 10;
    int &j = i;

    // ERROR
    // int &j;
    // j = i;

    increment(i);
    cout << "i is " << i << endl;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    int &k = f(i);
    j = k;
    cout << " j is " << j << " k is " << k << endl;

    int *k2 = f2();
    return 0;
}
