#include <iostream>
using namespace std;
// #include "Solution.h"

bool checkMember(int n)
{

    /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */
    int prev = 0;
    int curr = 1;
    int next;
    while (curr <= n)
    {
        if (prev == n || curr == n)
            return true;
        else
        {
            next = curr + prev;
            prev = curr;
            curr = next;
        }
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    if (checkMember(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
