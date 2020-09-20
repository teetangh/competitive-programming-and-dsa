#include <iostream>
using namespace std;

int isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    int n;
    cin >> n;
    int j = 2;
    for (int j = 2; j <= n; j++)
    {
        if (isPrime(j))
            cout << j << endl;
    }
}
// Sample Input 1:
// 9
// Sample Output 1:
// 2
// 3
// 5
// 7
// Sample Input 2:
// 20
// Sample Output 2:
// 2
// 3
// 5
// 7
// 11
// 13
// 17
// 19