#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    // have to declare amnd initialise simultaneously
    // const int i;
    // i =15;

    //cannot reinitialise
    const int i = 10;
    int const i2 = 10;
    // i = 12;

    // Const Reference from a non constant int
    int j = 12;
    const int &k = j;
    // k++;  //cannot modify the refernce
    j++;

    cout << j << endl;
    cout << k << endl;

    // Constant Reference from a const int
    int const j2 = 12;
    int const &k2 = j2;
    // j2++;
    // k2++;

    // Reference from a constant integer
    int const j3 = 123;
    // int &k3 = j3;
    // k3++;

    return 0;
}