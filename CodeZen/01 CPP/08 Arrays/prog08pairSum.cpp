#include <iostream>
using namespace std;
// #include "solution.h"

void pairSum(int input[], int size, int x)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[i] + input[j] == x)
            {
                if (input[i] <= input[j])
                    cout << input[i] << " " << input[j] << endl;
                else if (input[j] < input[i])
                    cout << input[j] << " " << input[i] << endl;
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
    pairSum(input, size, x);

    return 0;
}
// Sample Input 1:
// 1
// 9
// 1 3 6 2 5 4 3 2 4
// 7
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 9
// 1 3 6 2 5 4 3 2 4
// 12
// 6
// 2 8 10 5 -2 5
// 10
// Sample Output 2:
// 0
// 2


//  Explanation for Input 2:
// Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

// For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).