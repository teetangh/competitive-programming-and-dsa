#include <iostream>
using namespace std;

// won't change
void increment(int **p)
{
    p = p + 1;
}
// will change
void increment2(int **p)
{
    *p = *p + 1;
}
// will change
void increment3(int **p)
{
    **p = **p + 1;
}

int main(int argc, char const *argv[])
{
    int i = 10;
    int *p = &i;
    int **p2 = &p;

    // p2 -> p -> i
    cout << p2 << endl;
    cout << &p << endl;

    // ADDRES OF I
    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;

    // VALUE OF I
    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    return 0;
}
