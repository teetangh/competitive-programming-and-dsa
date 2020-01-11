#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int incFlag = 0;
    int decFlag = 0;
    int i = 1;
    int changeSeq = 0;
    if (arr[0] < arr[1])
    {
        incFlag = 1;
        decFlag = 0;
    }
    else if (arr[0] > arr[1])
    {
        incFlag = 0;
        decFlag = 1;
    }
incCheck:
    if (incFlag)
    {
        for (; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cout << false;
                exit(0);
            }
        }
    }

decCheck:
    if (decFlag)
    {
        for (; i < n; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                decFlag = 0;
                incFlag = 1;
                changeSeq++;
                goto incCheck;
            }
        }
    }

    if (changeSeq <= 1)
        cout << "true";
    else
        cout << "false";
}
