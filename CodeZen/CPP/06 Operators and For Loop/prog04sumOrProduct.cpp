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