// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// typedefs
typedef long long ll;
typedef long long int lli;


// Traversing the Hashmpa Once
// 
void pairSum3(int *arr, int size)
{
 
}


// Traversing the Hashmap Twice
// 
void pairSum2(int *arr, int size)
{
 
}


// Brute Force: Traversing the Rest of array for each element
// O(n^2) Time | O(1) space
void pairSum(int *arr, int size)
{
    int x = 0;
    //Write your code here
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                if (arr[i] <= arr[j])
                    cout << arr[i] << " " << arr[j] << endl;
                else
                    cout << arr[j] << " " << arr[i] << endl;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    pairSum(arr, n);

    delete[] arr;

    return 0;
}
