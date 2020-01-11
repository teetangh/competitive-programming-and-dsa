#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;
#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    int x = num / 10;
    int y = num % 10;

    if (x == 0)
    {
        if (num == 2)
        {
            cout << 'a';
            cout << 'b';
            cout << 'c';
        }
        if (num == 3)
        {
            cout << 'd';
            cout << 'e';
            cout << 'f';
        }
    }
    printKeypad(x);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
