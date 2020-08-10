#include <iostream>
#include <climits>
using namespace std;

int main()
{
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    int size;
    cin >> size;
    int sum = 0;

    int arr[100000000];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    for (int i = 0; i < size; i++)
        sum += arr[i];

    cout << sum;
}
