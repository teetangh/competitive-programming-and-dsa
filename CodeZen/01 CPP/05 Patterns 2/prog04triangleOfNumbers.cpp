#include <iostream>
using namespace std;

int main()
{
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << (i + j - 1);
        for (int j = 1; j <= (i - 1); j++)
            cout << (2 * i - 2 - j + 1);
        cout << endl;
    }
}
// Sample Input 1:
// 5
// Sample Output 1:
//     1
//    232
//   34543
//  4567654
// 567898765
// Sample Input 2:
// 4
// Sample Output 2:
//    1
//   232
//  34543
// 4567654