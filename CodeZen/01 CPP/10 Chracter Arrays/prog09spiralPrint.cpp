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
            ;
            count++;
        }
        ce--;
        for (j = ce, i = re; j >= cs; j--)
        {
            cout << input[i][j] << " ";
            ;
            count++;
        }
        re--;
        for (i = re, j = cs; i >= rs; i--)
        {
            cout << input[i][j] << " ";
            ;
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