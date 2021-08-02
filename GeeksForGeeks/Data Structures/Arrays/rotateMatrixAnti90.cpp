// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
// void swapUtil(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Your code goes here
    for (int i = 0; i < n; i++)
        for (int j = 0; i + j < n; j++)
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends