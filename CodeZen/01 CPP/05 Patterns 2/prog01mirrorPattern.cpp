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
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
// Sample Input 1:
// 3
// Sample Output 1:
//   1
//  12
// 123
// Sample Input 2:
// 4
// Sample Output 2:
//    1 
//   12
//  123
// 1234