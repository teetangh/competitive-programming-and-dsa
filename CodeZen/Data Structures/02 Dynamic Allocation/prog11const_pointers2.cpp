#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 10;
    int j = 21;

    // Pointer to constant integer
    int const *p = &i;
    // p++;
    p = &j;

    // Constant pointer to integer
    int *const p2 = &i;
    (*p2)++;
    // p2 = &j;

    // Constant pointer to constant integer
    int const *const p3 = &i;
    // (*p3)++;
    // p3 = &j;

    cout << " i is " << i << " j is " << j << endl;
    return 0;
}
