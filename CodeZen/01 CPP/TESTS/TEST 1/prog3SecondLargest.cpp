#include <iostream>
using namespace std;
#include <climits>

int main()
{

    // Write your code here
    int arr[10000];
    int n;
    cin >> n;

    int big1 = INT_MIN;
    int big2 = INT_MIN;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > big1)
        {
            big1 = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > big2 && arr[i] < big1)
        {
            big2 = arr[i];
        }
    }

    cout << big2;
}
// Sample Input 1:
//  4
//  3 9 0 9
// Sample Output 1:
//  3
// Sample Input 2 :
//  2
//  4 4
// Sample Output 2:
//  -2147483648
// Sample Output Explanation:
// Since both the elements are equal here, hence second largest element is INT_MIN i.e. ( -2^31 )