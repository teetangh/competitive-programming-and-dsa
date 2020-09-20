#include <iostream>
// #include "solution.h"
using namespace std;

void print2DArray(int **input, int row, int col)
{
    // Write your code here
    int i, j, k;
    int *rowCount = new int[row];
    for (i = 0; i < row; i++)
        rowCount[i] = row - i - 1;

    // for(i = 0 ; i < row ; i++ )
    //     cout<<rowCount[i];

    for (i = 0; i < row;)
    {
        for (j = 0; j < col; j++)
        {
            cout << input[i][j] << ' ';
        }
        cout << endl;

        if (rowCount[i] == 0)
            i++;
        else
            rowCount[i]--;
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    int **input = new int *[row];
    for (int i = 0; i < row; i++)
    {
        input[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    print2DArray(input, row, col);
}
// Sample Input :
// 3 3
// 1    2    3
// 4    5    6
// 7    8    9
// Sample Output :
// 1    2    3
// 1    2    3
// 1    2    3
// 4    5    6
// 4    5    6
// 7    8    9