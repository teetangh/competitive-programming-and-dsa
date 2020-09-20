#include <iostream>
using namespace std;
// #include "Solution.h"

bool checkMember(int n)
{
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
// Sample Input 1 :
// 5
// Sample Output 1 :
// true
// Sample Input 2 :
// 14
// Sample Output 2 :
// false