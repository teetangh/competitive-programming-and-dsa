#include <iostream>
#include <algorithm>
using namespace std;
// #include "solution.h"

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {

        for (int j = 0; j < size2; j++)
        {
            if (input1[i] == input2[j])
            {
                input2[j] = -99999;
                cout << input1[i] << endl;
                break;
            }
        }
    }
}

int main()
{

    int size1, size2;

    cin >> size1;
    int *input1 = new int[1 + size1];

    for (int i = 0; i < size1; i++)
        cin >> input1[i];

    cin >> size2;
    int *input2 = new int[1 + size2];

    for (int i = 0; i < size2; i++)
        cin >> input2[i];

    intersection(input1, input2, size1, size2);

    return 0;
}
// Sample Input 1 :
// 2
// 6
// 2 6 8 5 4 3
// 4
// 2 3 4 7 
// 2
// 10 10
// 1
// 10
// Sample Output 1 :
// 2 4 3
// 10
// Sample Input 2 :
// 1
// 4
// 2 6 1 2
// 5
// 1 2 3 4 2
// Sample Output 2 :
// 2 1 2
// Explanation for Sample Output 2 :
// Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.