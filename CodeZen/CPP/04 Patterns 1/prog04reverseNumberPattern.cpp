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
        for (int j = i; j >= 1; j--)
            cout << j;
        for (int j = 1; j <= N - i; j++)
            cout << " ";
        cout << endl;
    }
}
