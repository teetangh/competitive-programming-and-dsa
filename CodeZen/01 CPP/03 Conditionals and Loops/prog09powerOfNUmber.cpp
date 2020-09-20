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
// Sample Input 1 :
//  3 4
// Sample Output 1 :
// 81
// Sample Input 2 :
//  2 5
// Sample Output 2 :
// 32