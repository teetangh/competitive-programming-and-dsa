#include <iostream>
using namespace std;

int main()
{
    // Write your code here

    int num;
    cin >> num;

    int last;
    int rev = 0;

    while (num != 0)
    {
        last = num % 10;
        rev = (rev * 10) + last;
        num = num / 10;
    }
    cout << rev;
}
