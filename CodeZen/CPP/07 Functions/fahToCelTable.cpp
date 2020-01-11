#include <iostream>
using namespace std;
// #include "Solution.h"

void printTable(int start, int end, int step)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

    int c;
    for (int i = start; i <= end; i = i + step)
    {
        c = ((i - 32) * ((float)5 / 9));
        cout << i << "\t" << c << endl;
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;

    printTable(start, end, step);
}
