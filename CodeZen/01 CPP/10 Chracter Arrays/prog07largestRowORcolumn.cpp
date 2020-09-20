#include <iostream>
using namespace std;
// #include "Solution.h"

void findLargest(int arr[][1000], int row, int col)
{

    /* Don't writerowain().
   *  Don't read input, it is passed as function argument.
   * Print output as specified in the question.
   */

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
    int *rowsum = new int[row];
    int *colsum = new int[col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            rowsum[i] += arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            colsum[j] += arr[i][j];
        }
    }
    int colmax = -2147483648;
    int rowmax = -2147483648;

    int colmaxIndex = -2147483648;
    int rowmaxIndex = -2147483648;

    for (int i = 0; i < col; i++)
    {
        if (rowsum[i] > rowmax)
        {
            rowmax = rowsum[i];
            rowmaxIndex = i;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (colsum[j] > colmax)
        {
            colmax = colsum[j];
            colmaxIndex = j;
        }
    }
    if (rowmax >= colmax)
    {
        cout << "row " << rowmaxIndex << " " << rowmax;
    }
    else
        cout << "column " << colmaxIndex << " " << colmax;
}

int main()
{
    int row, col;
    cin >> row >> col;

    int input[1000][1000];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    findLargest(input, row, col);
}

// Sample Input 1 :
// 1
// 2 2 
// 1 1 
// 1 1
// Sample Output 1 :
// row 0 2
// Sample Input 2 :
// 2
// 3 3
// 3 6 9 
// 1 4 7 
// 2 8 9
// 4 2
// 1 2
// 90 100
// 3 40
// -10 200
// Sample Output 2 :
// column 2 25
// column 1 342