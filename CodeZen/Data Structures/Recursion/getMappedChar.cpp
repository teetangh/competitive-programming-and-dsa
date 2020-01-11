#include <iostream>
#include <string.h>
using namespace std;

char getMappedChar(char myChar)
{
    char i = myChar - '0';
    return 'a' + i - 1;
}
int main()
{
    int temp='12';
    char c = temp;
    cout << c;
}