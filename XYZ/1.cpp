#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

class A
{

public:
    A()
    {
        cout << "1";
    }
    virtual ~A()
    {
        cout << "2";
    }
};
class B : public A
{

public:
    B()
    {
        cout << "3";
    }
    ~B()
    {
        cout << "4";
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    char str1[] = "Hello";
    char str2[] = "World";
    str1 = str2;
    printf("%s%s", str1, str2);

    return 0;
}
