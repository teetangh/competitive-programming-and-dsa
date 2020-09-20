#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char startChar = 'A' + i + j - 2;
            cout << startChar;
        }
        cout << endl;
    }
}
// Sample Input 1:
// 5
// Sample Output 1:
// A
// BC
// CDE
// DEFG
// EFGHI
// Sample Input 2:
// 6
// Sample Output 2:
// A
// BC
// CDE
// DEFG
// EFGHI
// FGHIJK