#include <iostream>
using namespace std;
// #include "Solution.h"

int length(char input[])
{
    int i = 0;
    int count = 0;
    while (input[i] != '\0')
    {
        ++count;
        i++;
    }
    return count;
}

void printSubstrings(char input[])
{
    /* Don't write main().
   *  Don't read input, it is passed as function argument.
   * Print output as specified in the question.
   */
    int n = length(input);
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k < j; k++)
                cout << input[k];
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{

    char str[10000];
    cin.getline(str, 10000);

    printSubstrings(str);
}
// Sample Input 1 :
// xyz
// Sample Output 1 :
// x
// xy
// xyz
// y
// yz
// z
// Sample Input 2 :
// ab
// Sample Output 2 :
// a
// b
// ab