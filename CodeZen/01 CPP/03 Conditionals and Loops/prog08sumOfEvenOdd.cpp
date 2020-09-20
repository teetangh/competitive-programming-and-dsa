#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int evenSum = 0;
    int oddSum = 0;
    long number;

    cin >> number;
    int lastDigit;

    while (number != 0)
    {
        lastDigit = number % 10;
        if (lastDigit % 2 == 0)
            evenSum = evenSum + lastDigit;
        else
            oddSum = oddSum + lastDigit;
        number = number / 10;
    }

    cout << evenSum << " " << oddSum;
    return 0;
}
// Sample Input 1:
// 1234
// Sample Output 1:
// 6 4
// Sample Input 2:
// 552245
// Sample Output 2:
// 8 15