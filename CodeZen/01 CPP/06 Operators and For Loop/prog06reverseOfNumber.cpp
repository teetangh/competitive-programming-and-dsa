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
// Sample Input 1 :
// 1234
// Sample Output 1 :
// 4321
// Sample Input 2 :
// 1980
// Sample Output 2 :
// 891