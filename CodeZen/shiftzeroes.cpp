// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{

    int arr[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int j;
    for (int i = 0; i < n; i++)
    {
        while (arr[i] == 0)
        {
            for (j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            arr[j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    // Write your code here
}