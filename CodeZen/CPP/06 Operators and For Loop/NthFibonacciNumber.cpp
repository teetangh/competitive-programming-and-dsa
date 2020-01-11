#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin >> n;
    int prev = 0;
    int curr = 1;
    int next;
    for (int i = 1; i <= n; i++)
    {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    cout << prev;
}
