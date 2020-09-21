#include <iostream>
using namespace std;

int main()
{
    // Creating stuff in heap memory
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    // More stuff
    double *pd = new double;
    char *c = new char;

    // Integer array of defined size in heap
    // 200 bytes in the heap
    // 8 bytes in the stack
    int *pa = new int[50];

    // Declaring a user-defined size dynamically allocated array in heap
    int n;
    cin >> n;

    int *pa2 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> pa2[i];

    // Calculating the maximum in the array
    int max = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < pa2[i])
            max = pa2[i];
    }
    // Printing the maximum element
    cout << "MAX IS " << max << endl;

    // MEMORY CONSUMPTION EVENTUALLY FULL
    // HAS TO BE DELETED AFTER USE
    // while (true)
    // {
    //     int *p = new int;
    // }

    // Syntax for deleting dynamically allocated variables and arrays
    int *temp = new int;
    delete temp;

    // Single Element Deletion
    temp = new int;
    delete temp;

    // Array Deletion
    temp = new int[100];
    delete[] p;
}
// // Sample IO
// 10
// 5
// 6
// 7
// 8
// 9
// 10
// MAX IS 10