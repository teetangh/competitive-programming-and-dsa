#include <iostream>
using namespace std;

// arr - input array
// n - size of array
// val - element to be searched
int BinarySearch(int arr[], int n, int val)
{

    int lb = 0;
    int ub = n - 1;

    int mid = (lb + ub) / 2;

    if (lb < ub)
    {
        if (arr[mid] == val)
            return mid;
        else if (val < arr[mid])
        {
            cout << "Debug 1" << endl;
            ub = mid - 1;
            return BinarySearch(arr, ub - lb + 1, val);
        }
        else if (val > arr[mid])
        {
            cout << "Debug 2" << endl;
            lb = mid + 1;
            return BinarySearch(arr, ub - lb + 1, val);
        }
    }
    return -1;
}

int main()
{

    int size, val;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cin >> val;
    cout << BinarySearch(input, size, val);
    return 0;
}
