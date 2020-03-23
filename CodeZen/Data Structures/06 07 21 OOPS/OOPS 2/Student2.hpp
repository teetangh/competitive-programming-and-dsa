#include <iostream>
#include <string.h>
using namespace std;
class Student2
{
private:
public:
    int age;
    const int rollNumber;
    int &x;

    // ERROR GARBAGE INITIALISATION
    // Student2(int r)
    // {
    //     rollNumber = r;
    // }

    _INITIALIZER_LIST
    // Student2(int r) : rollNumber(r) {}                                  //const int rollNumber = r;
    Student2(int r, int age) : rollNumber(r), age(age), x(this->age) {} // HERE THIS KEYWORD this->age(age) is implied

    // ~Student2();
};
