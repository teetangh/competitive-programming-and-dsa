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
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << (n - i + 1);
        }
        cout << endl;
    }
}
// Sample Input 1:
// 5
// Sample Output 1:
// 55555 
// 4444
// 333
// 22
// 1
// Sample Input 2:
// 6
// Sample Output 2:
// 666666
// 55555 
// 4444
// 333
// 22
// 1