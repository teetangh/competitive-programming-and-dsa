#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

struct Interval
{
    int st;
    int et;
};

bool compare(Interval i1, Interval i2) { return i1.st < i2.st; }
bool compare2(Interval i1, Interval i2) { return i1.st > i2.st; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    // arr
    Interval arr[] = {{6, 4}, {3, 2}, {4, 6}, {8, 13}};

    sort(arr, arr + 4, compare);
    for (int i = 0; i < 4; i++)
        cout << arr[i].st << ":" << arr[i].et << endl;
    cout << endl;

    sort(arr, arr + 4, compare2);
    for (int i = 0; i < 4; i++)
        cout << arr[i].st << ":" << arr[i].et << endl;
    cout << endl;

    // arr2
    int arr2[] = {1, 3, 2, 5, 7, 6};
    sort(arr2, arr2 + 6, less<int>());
    // sort(arr2, arr2 + 6, greater<int>());

    for (int i = 0; i < 6; i++)
        cout << arr2[i] << " ";
    cout << endl;

    cout << binary_search(arr2, arr2 + 6, 8) << endl;

    // For elements that are present
    cout << lower_bound(arr2, arr2 + 6, 7) - arr2 << endl;

    // For elements that are NOT present
    cout << lower_bound(arr2, arr2 + 6, 4) - arr2 << endl; // Returns the index after which there is higher element

    cout << upper_bound(arr2, arr2 + 6, 3) - arr2 << endl;

    cout << upper_bound(arr2, arr2 + 6, 4) - arr2 << endl;

    cout << __gcd(10, 6) << endl;
    cout << pow(2.7, 5) << endl;

    int x = 10;
    int y = 12;
    cout << x << y << endl;

    cout << min(14, 17) << endl;
    return 0;
}
