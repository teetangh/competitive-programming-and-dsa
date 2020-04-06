#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int arr[1000][1000];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int *colsum = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            colsum[j] += arr[i][j];
        }
    }
}
