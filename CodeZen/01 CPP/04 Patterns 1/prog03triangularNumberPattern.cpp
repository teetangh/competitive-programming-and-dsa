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
            cout << i;
        for (int j = 1; j <= N - i; j++)
            cout << " ";
        cout << endl;
    }
}
// Sample Input 1:
// 5
// Sample Output 1:
// 1
// 22
// 333
// 4444
// 55555
// Sample Input 2:
// 6
// Sample Output 2:
// 1
// 22
// 333
// 4444
// 55555
// 666666