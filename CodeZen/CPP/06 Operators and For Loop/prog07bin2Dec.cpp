#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int last;

    int decimal = 0;
    int i = 0;
    while (num != 0)
    {
        last = num % 10;
        decimal += last * pow(2, i++);
        num /= 10;
    }

    cout << decimal;
}
