#include <iostream>
// #include "solution.h"
using namespace std;

void wavePrint(int input[][1000], int row, int col)
{
    /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < row; i++)
                std::cout << input[i][j] << " ";
        }
        else
        {
            for (int i = row - 1; i >= 0; i--)
                std::cout << input[i][j] << " ";
        }
    }
}

int main()
{
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    wavePrint(input, row, col);
}

// Sample Input 1:
// 1
// 3 4 
// 1  2  3  4 
// 5  6  7  8 
// 9 10 11 12
// Sample Output 1:
// 1 5 9 10 6 2 3 7 11 12 8 4
// Sample Input 2:
// 2
// 5 3 
// 1 2 3 
// 4 5 6 
// 7 8 9 
// 10 11 12 
// 13 14 15
// 3 3
// 10 20 30 
// 40 50 60
// 70 80 90
// Sample Output 2:
// 1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
// 10 40 70 80 50 20 30 60 90 