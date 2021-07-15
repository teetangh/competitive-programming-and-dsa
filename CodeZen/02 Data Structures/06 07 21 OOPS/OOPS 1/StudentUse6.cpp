#include <iostream>
using namespace std;
#include "include/Student.hpp"

int main(int argc, char const *argv[])
{
    Student s1; // Default Constructor called

    Student s2(101);     // Parameterized Constructor 1 called
    Student s3(20, 102); // Parameterized Constructor 1 called

    Student s4(s3);      // Copy Constructor

    s1 = s2; // Copy assignment operator

    // Internally Copy assignment operator called
    Student s5;
    s5 = s4;
}
