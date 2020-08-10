#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << i << endl;

    i++;
    cout << i << endl;

    // Dangling Pointers(Very Dangerous)
    int *p;
    cout << p << endl;
    cout << *p << endl;
    (*p)++;
    cout << p << endl;
    cout << *p << endl;
    // Segmentation Fault
    int *q = 0;
    (*q)++;
    cout << q << endl;
    cout << *q << endl;
}