#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n, int d)
{
    int i;
    for (i = d; i < n + d; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void cyclicshift(int arr[], int n, int d)
{
    int i;
    int c = 0;
    for (i = n; i < n + d; i++)
    {
        arr[i] = arr[c++];
    }
    display(arr, n, d);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int d;
        cin >> n >> d;
        int arr[n + d];
        int i;
        for (i = 0; i < n + d; i++)
            arr[i] = 0;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cyclicshift(arr, n, d);
    }
}