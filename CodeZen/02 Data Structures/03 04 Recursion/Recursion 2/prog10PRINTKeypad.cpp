#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

#include <iostream>
#include <string>
using namespace std;
void printCombination(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int x = num / 10;
    int y = num % 10;
    string temp;
    switch (y)
    {
    case 2:
        temp = "abc";
        break;
    case 3:
        temp = "def";
        break;
    case 4:
        temp = "ghi";
        break;
    case 5:
        temp = "jkl";
        break;
    case 6:
        temp = "mno";
        break;
    case 7:
        temp = "pqrs";
        break;
    case 8:
        temp = "tuv";
        break;
    case 9:
        temp = "wxyz";
        break;
    }
    for (int i = 0; i < temp.size(); i++)
        printCombination(x, temp[i] + output);
}

void printKeypad(int num)
{
    string output = " ";
    printCombination(num, output);
}
// #include <iostream>
// #include <string>
// using namespace std;
// void printCombination(int num, string output)
// {
//     int x = num / 10;
//     int y = num % 10;
//     string temp;

//     // cout << " x " << x << " y " << y << " num " << num << endl;

//     switch (y)
//     {
//     case 2:
//         temp = "abc";
//         break;
//     case 3:
//         temp = "def";
//         break;
//     case 4:
//         temp = "ghi";
//         break;
//     case 5:
//         temp = "jkl";
//         break;
//     case 6:
//         temp = "mno";
//         break;
//     case 7:
//         temp = "pqrs";
//         break;
//     case 8:
//         temp = "tuv";
//         break;
//     case 9:
//         temp = "wxyz";
//         break;
//     }
//     // cout << " temp " << temp << endl;
//     // cout << " output " << output << endl;
//     if (x == 0)
//     {
//         output = ' ';
//         cout << output;
//         return;
//     }
//     // cout << output;
//     for (int i = 0; i < temp.size(); i++)
//         for (int j = 0; j < output.size(); j++)
//             cout << output + temp[i] << endl;
//     printCombination(x, output);
// }
// void printKeypad(int num)
// {
//     string output = "";

//     printCombination(num, output);
// }

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
