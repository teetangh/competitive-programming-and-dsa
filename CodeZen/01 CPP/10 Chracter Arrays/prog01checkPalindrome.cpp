#include <iostream>
using namespace std;
// #include "Solution.h"

bool checkPalindrome(char str[])
{

    /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int j = 0;
    int count = 0;
    while (str[j] != NULL)
    {
        count++;
        j++;
    }
    int n = count;

    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] == str[n - i - 1])
            continue;
        else
            return false;
    }
    return true;
}

int main()
{

    char str[10000];
    cin.getline(str, 10000);

    if (checkPalindrome(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
