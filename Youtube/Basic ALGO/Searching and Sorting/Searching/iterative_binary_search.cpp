#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
//     freopen("input1.txt", "r", stdin);
//     freopen("output1.txt", "w", stdout);
// #endif

    int size;
    cin >> size;
    int elements;
    vector<int> vec;
    while (size--)
    {
        cin >> elements;
        vec.push_back(elements);
    }

    int key;
    cin >> key;

    int low = 0, high = vec.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] == key)
        {
            cout << "Element foumd at position " << mid << endl;
            break;
        }
        else if (key < vec[mid])
            high = mid - 1;
        else if (key > vec[mid])
            low = mid + 1;
    }

    if (low > high)
        cout << "Element Not found" << endl;

    return 0;
}
// Sample IO
// 5
// 1 2 3 4 5
// 4

// Element foumd at position 3