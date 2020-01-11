#include <iostream>
// #include "solution.h"
using namespace std;
using namespace std;
int length(char input[])
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
        count++;
    return count;
}
void replacePi(char input[])
{
    // Write your code here
    int n = length(input);
    if (n == 0 || n == 1)
        return;
    else
    {
        if (input[0] != 'p' && input[0] != 'i')
        {
            // cout << "debug1" << endl;
            // cout << input[0] << endl;
            replacePi(input + 1);
        }
        if (input[0] == 'i' || (input[0] == 'p' && input[1] != 'i'))
        {
            // cout << "debug2" << endl;
            // cout << input[0];
            replacePi(input + 1);
        }

        else if (input[0] == 'p' && input[1] == 'i')
        {
            // cout << "debug3" << endl;
            for (int i = n; i >= 0; i--)
                input[i + 2] = input[i];
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
            replacePi(input + 1);
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
