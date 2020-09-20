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
// Sample Input 1 :
// 1100
// Sample Output 1 :
// 12
// Sample Input 2 :
// 111
// Sample Output 2 :
// 7