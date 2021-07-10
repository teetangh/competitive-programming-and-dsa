#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col)
{
    /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	* Taking input is handled automatically.
	*/
    int limit = row * col;

    int rs = 0;
    int re = row - 1;

    int cs = 0;
    int ce = col - 1;

    int i = rs;
    int j = cs;
    int count = 0;
    while (count < limit)
    {
        for (j = cs, i = rs; j <= ce; j++)
        {
            cout << input[i][j] << " ";
            count++;
        }
        rs++;
        for (i = rs, j = ce; i <= re; i++)
        {
            cout << input[i][j] << " ";
            count++;
        }
        ce--;
        for (j = ce, i = re; j >= cs; j--)
        {
            cout << input[i][j] << " ";
            count++;
        }
        re--;
        for (i = re, j = cs; i >= rs; i--)
        {
            cout << input[i][j] << " ";
            count++;
        }
        cs++;
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
    spiralPrint(input, row, col);
}

// Sample Input 1:
// 1
// 4 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// Sample Output 1:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Sample Input 2:
// 2
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3 1
// 10
// 20
// 30
// Sample Output 2:
// 1 2 3 6 9 8 7 4 5
// 10 20 30