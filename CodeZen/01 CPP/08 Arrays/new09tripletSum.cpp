#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int n, int x)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    if (arr[i] < arr[j] && arr[j] < arr[k])
                        cout << arr[i] << " " << arr[j] << " " << arr[k];
                    else if (arr[i] < arr[k] && arr[k] < arr[j])
                        cout << arr[i] << " " << arr[k] << " " << arr[j];
                    else if (arr[j] < arr[i] && arr[i] < arr[k])
                        cout << arr[j] << " " << arr[i] << " " << arr[k];
                    else if (arr[j] < arr[k] && arr[k] < arr[i])
                        cout << arr[j] << " " << arr[k] << " " << arr[i];
                    else if (arr[k] < arr[i] && arr[i] < arr[j])
                        cout << arr[k] << " " << arr[i] << " " << arr[j];
                    else if (arr[k] < arr[j] && arr[j] < arr[i])
                        cout << arr[k] << " " << arr[j] << " " << arr[i];
                    cout << endl;
                }
            }
        }
    }
}

int main()
{

    int size;

    int x;
    cin >> size;

    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;

    FindTriplet(input, size, x);

    return 0;
}
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7
// 12
// Sample Output 1:
// 5
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7
// 19
// 9
// 2 -5 8 -6 0 5 10 11 -3
// 10
// Sample Output 2:
// 0
// 5

//  Explanation for Input 2:
// Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

// For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)