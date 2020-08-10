#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Write your code here

    // int base,expon;
    // cin>>base>>expon;
    // cout<<pow(base,expon);

    int tempbase, tempexpon;
    int result = 1;
    cin >> tempbase >> tempexpon;

    for (int i = 1; i <= tempexpon; i++)
    {
        result = result * tempbase;
    }

    cout << result;
}
