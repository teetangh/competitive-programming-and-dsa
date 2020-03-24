#include <iostream>
// #include "solution.h"prgo
using namespace std;

int binarySearch(int input[], int size, int element)
{
    if (size == 0)
        return -1;
    // Write your code here
    int lb = 0;
    int ub = size - 1;
    int mid = (lb + ub) / 2;

    if (element == input[mid])
        return mid;

    else if (element < input[mid])
        return binarySearch(input, mid, element);

    else if (element > input[mid])
    {
        int ans = binarySearch(input + mid + 1, size - mid - 1, element);

        if (ans == -1)
            return -1;

        return mid + 1 + ans;
    }
    else
        return -1;
}

// // input - input array
// // size - length of input array
// // element - value to be searched
//  int binarySearch(int input[], int size, int element) {
//      // Write your code here
//      if(size==0){
//          return -1;
//      }
//      int lb = 0;
//      int ub = size - 1;
//      int mid = (lb + ub)/2;

//     if(lb <= ub)
//     {
//          if(element == input [mid])
//              return mid;

//          else if(element < input [mid])
//              return  binarySearch(input , mid, element);

//          else if(element > input[mid])
//              return mid + binarySearch(input + mid+1, ub - mid+1 , element);
//      }
//      else
//          return -1;
//  }

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
