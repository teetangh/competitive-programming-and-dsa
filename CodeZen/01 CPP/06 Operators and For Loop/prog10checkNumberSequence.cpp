#include <iostream>
using namespace std;
int main()
{
    // Write your code here
    int n;
    cin >> n;
    int arr[10000];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int incFlag = 0;
    int decFlag = 0;
    int i = 1;
    int changeSeq = 0;
    if (arr[0] < arr[1])
    {
        incFlag = 1;
        decFlag = 0;
    }
    else if (arr[0] > arr[1])
    {
        incFlag = 0;
        decFlag = 1;
    }
incCheck:
    if (incFlag)
    {
        for (; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cout << "false";
                exit(0);
            }
        }
    }
decCheck:
    if (decFlag)
    {
        for (; i < n - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                decFlag = 0;
                incFlag = 1;
                changeSeq++;
                goto incCheck;
            }
        }
    }
    if (changeSeq <= 1)
        cout << "true";
    else
        cout << "false";
}
// Sample Input 1 :
// 5
// 9
// 8
// 4
// 5
// 6
// Sample Output 1 :
// true
// Sample Input 2 :
// 3
// 1
// 2
// 3
// Sample Output 2 :
// true
// Sample Input 3 :
// 3
// 8
// 7
// 7
// Sample Output 3 :
// false
// Explanation for Sample Format 3 :
// 8 7 7 is not strictly decreasing, so output is false.
// Sample Input 4 :
// 6
// 8
// 7
// 6
// 5
// 8
// 2
// Sample Output 4 :
// false
// Explanation for Sample Input 4 :
// The series is :
// 8 7 6 5 8 2
// It is strictly decreasing first (8 7 6 5). Then it's strictly increasing (5 8). But then it starts strictly decreasing again (8 2). Therefore, the output for this test case is 'false'