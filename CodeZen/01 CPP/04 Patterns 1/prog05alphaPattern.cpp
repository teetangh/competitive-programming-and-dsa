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
        char startChar = 'A' + i - 1;
        for (int j = 1; j <= i; j++)
            cout << startChar;
        cout << endl;
    }
}
// Sample Input 1:
// 7
// Sample Output 1:
// A
// BB
// CCC
// DDDD
// EEEEE
// FFFFFF
// GGGGGGG
// Sample Input 2:
// 6
// Sample Output 2:
// A
// BB
// CCC
// DDDD
// EEEEE
// FFFFFF