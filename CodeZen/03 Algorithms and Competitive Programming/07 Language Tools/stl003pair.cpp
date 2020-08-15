#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    pair<int, char> p;
    p = std::make_pair(2, 'b');
    cout << p.first << " " << p.second << endl;

    pair<int, char> p2(1, 'a');
    cout << p2.first << " " << p2.second << endl;
}
// // Sample IO
// 2 b
// 1 a
