#include <iostream>
using namespace std;
#define PI 3.142
int main()
{
    int r;
    cin >> r;

    // double pi = 3.14 * r * r;
    // pi = pi + 1;

    // 1. No Performance Hit
    // 2. NO extra memory usage
    // 3. Cannot be changed by others later
    cout << PI * r * r << endl;
}
// // Sample IO
// 5
// 78.55