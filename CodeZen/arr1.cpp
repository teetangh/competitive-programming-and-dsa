#include <iostream>
using namespace std;
#define size 3

int main()
{
    int arr[size] = {9, 9, 9};

    int digitSum = 0;
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        num = (num * 10) + arr[i];
    }

    do
    {
        if (digitSum > 10)
        {
            num = digitSum;
            digitSum = 0;
        }
        while (num != 0)
        {
            digitSum += num % 10;
            num = num / 10;
        }

    } while (digitSum > 10);

    cout << digitSum;
}
