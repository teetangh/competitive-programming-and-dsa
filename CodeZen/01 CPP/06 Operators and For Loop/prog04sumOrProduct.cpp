#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int tempSum = 0;
    int tempProduct = 1;

    int n;
    int choice;
    cin >> n >> choice;

    if (choice == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            tempSum += i;
        }
        cout << tempSum;
    }
    else if (choice == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            tempProduct *= i;
        }
        cout << tempProduct;
    }
    else
        cout << -1;
}
// Sample Input 1 :
// 10
// 1
// Sample Output 1 :
// 55
// Sample Input 2 :
// 10
// 2
// Sample Output 2 :
// 3628800
// Sample Input 3 :
// 10
// 4
// Sample Output 3 :
// -1