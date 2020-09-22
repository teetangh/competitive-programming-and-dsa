#include <iostream>
using namespace std;

void removeX(char s[])
{
    // Base Case
    if (s[0] == '\0')
        return;

    // Recursive Call
    if (s[0] != 'x') //If the first character was x
        removeX(s + 1);
    else //if not then just shift the rest of characters
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
            s[i - 1] = s[i];
        s[i - 1] = s[i];
        removeX(s);
    }
}

int length(char s[])
{
    if (s[0] == '\0')
        return 0;
    int smallStringLength = length(s + 1);
    return 1 + smallStringLength;
}

int main()
{
    char str[100];
    cin >> str;

    int l1 = length(str);
    cout << l1 << endl;
    cout << str << endl;
    removeX(str);
    int l2 = length(str);
    cout << l2 << endl;
    cout << str << endl;
}
