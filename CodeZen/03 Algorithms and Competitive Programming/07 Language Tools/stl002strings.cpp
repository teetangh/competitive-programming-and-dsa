#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    string s = "Kaustav";
    string s1(s, 2, 4);
    cout << s << endl;
    cout << s1 << endl;

    string s2 = s.substr(1, 4);
    cout << s2 << endl;

    if (s1.compare(s2) == 0)
        cout << s1 << "is equal to " << s2 << endl;
    else
        cout << s1 << "is NOT equal to " << s2 << endl;

    return 0;
}
