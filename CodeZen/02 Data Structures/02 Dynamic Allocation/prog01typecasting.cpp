#include <iostream>
using namespace std;

int main()
{
    int i = 65;
    char c = i;
    cout << c << endl;

    int *p = &i;
    char *pc = (char *)p; //typecasting

    cout << endl;
    cout << p << endl;   //Prints the address of pointer
    cout << pc << endl;  //Prints till null character
    cout << *p << endl;  //Reading as an integer
    cout << *pc << endl; //Reading as a character
    cout << endl;

    cout << *(pc) << endl;
    //NULL OUTPUT
    // cout << *(pc + 1) << endl;
    // cout << *(pc + 2) << endl;
    // cout << *(pc + 3) << endl;
}

// // Output
// A

// 0x7ffebcf5d914
// A
// 65
// A

// A