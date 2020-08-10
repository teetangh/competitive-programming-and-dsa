#include <iostream>
using namespace std;

// default arguments work only from right  to left
int sum(int a[], int size, int si = 0)
{
    int ans = 0;
    for (int i = si; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}
int sum2(int a, int b = 0, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main(int argc, char const *argv[])
{
    int arr[5];

    // input code;
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    cout << sum(arr, 5) << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << sum2(a, b, c, d) << endl;

    return 0;
}
// Sample IO
// 1 2 3 4 5
// 15
// 5 6 7 8
// 26