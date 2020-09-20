#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; count < n; i++)
    {
        if ((3 * i + 2) % 4 == 0)
            continue;
        cout << (3 * i + 2) << " ";
        count++;
    }
}
// Sample Input 1 :
// 10
// Sample Output 1 :
// 5 11 14 17 23 26 29 35 38 41
// Sample Input 2 :
// 4
// Sample Output 2 :
// 5 11 14 17