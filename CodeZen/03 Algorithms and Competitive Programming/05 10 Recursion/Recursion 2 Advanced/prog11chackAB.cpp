#include <iostream>
using namespace std;

bool checkAB(char input[])
{
    // Write your code here
    bool answer = true;
    if (input[0] == 'P' && input[1] == '\0')
        return true;
    if (input[0] != 'P')
    {
        if (input[0] == 'a' && (input[1] == '\0' || input[1] == 'a' || (input[1] == 'b' && input[2] == 'b')))
        {
            input[0] = 'P';
            return checkAB(input);
        }
        else
            return false;
    }
    else if (input[0] == 'P')
    {
        if (input[1] == 'a' && (input[2] == '\0' || input[2] == 'a' || (input[2] == 'b' && input[3] == 'b')))
            answer = true;
        else if (input[1] == 'a' && (input[2] == 'b' && input[3] == 'a'))
            answer = false;

        if (input[1] == 'b' && input[2] == 'b' && (input[3] == '\0' || input[3] == 'a'))
            answer = true;
        else if (input[1] == 'b' && input[2] == 'b' && input[3] == 'b')
            answer = false;
    }

    if (answer == false)
        return false;
    else
    {
        input[1] = 'P';
        return checkAB(input + 1);
    }
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
